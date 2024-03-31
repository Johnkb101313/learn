## TCP 三次握手(three-way handshake)
目的:建立一個可靠的connection ()

1. 雙方一開始都係close狀態
2. Server Side開始listen一個port (when call .listen())
3. Client Side的OS開始向Server Side發出一個Message (SYN Message) (when call .connect())
這是第一次既握手, 目的是確認Server Side既情況, Server Side是否ready
該次既SYN Message當中會初始化一個client_isn(isn 為序列), Set SYN flag True(1)
(按照約定Server Side會將client_isn當中的值+1以表示自己已經ready好)
到目前為止, 第一次握手已完成, Client Side而家既狀態為SYN_SENT

4. Server Side而家準備回傳頭先收到既Message(SYN Message), 目前狀態為 (client_isn + 1) (SYN flag True(1))
Server Side 初始化 server_isn 并且將 ACK flag Set True(1) 準備將該 Message 回傳, 該Message稱SYN + ACK Message
(按照約定Client Side會將server_isn當中的值+1以表示自己已經ready好)
SYN + ACK Message到達Client Side, 而家Server Side既狀態改為SYN_RECV, 完成第二次握手
SYN + ACK Message:
...
client_isn + 1
server_isn
SYN flag (1)
ACK flag (1)
...

5. Client Side接收到 SYN + ACK Message, 按照約定將server_isn + 1, ACK flag Set True(1), SYN flag not True(0)

完成三次握手後Server Side既.accept()會開始進行工作(return new socket and client side info(ip, port))

## TCP 四次揮手()
目的關閉 Client Side 和 Server Side 的收發功能, 關閉這一次的connection
想要發起四次揮手 Client Side 要先發起.close(), 操作系統向 Server Side 發起 FIN Message
1. Client Side FIN, 1000
Server Side 開始關閉應用層socket的收功能(.recv()), 操作系統收到FIN Message并返回 ACK Message 給 Client Side
2. ACK, 1000 + 1
由於 Server Side 需要一段時間關閉收功能, 導致第二次揮手和第三次揮手分開, 不能同時進行
```
if len(recv(1024)) == 0:
    connection_socket.close()
```
, 等到 Server Side 關閉應用層socket的收功能後(.recv()), .close()使操作系統返回 FIN Message 給 Client Side 以通知 Client Side 自己不會再send野比 Client Side, Client Side 收到後會關閉應用層socket的收功能(.recv()), 并返回 ACK Message 給 Server Side
3. FIN, 2000
4. ACK, 2000 + 1

每次的FIN Message都係由.close()發起, 所以第一次既揮手同第三次揮手都由應由層主導發起 == FIN Message

每個在網絡中的數據包存在時間為MSL(大約一分鐘)
如果一方發現對方沒有傳回ACK Message
會重發上一次既數據包

因此最後如果第三次揮手後 Server Side 沒有收到 Client Side 操作系統傳回既 ACK Message
Server Side 唔知 Client Side 有冇收到第三次揮手, 此時 Server Side 如果等咗一次MSL既時間都未收到 Client Side 操作系統傳回 ACK Message, 會認為 Client Side 未收到第三次揮手傳過去既 FIN Message, Server Side 又會重發 FIN Message

最後 Client Side 收到FIN Message會保留一定資源等待 Server Side 是否會再回傳 多一次 FIN Message 確保 Server Side 已收到, 所以 Server Side 只有兩次機會重發 FIN Message??????????????????

可見TCP有應答機制, UDP沒有, 因此TCP更加穩定. 好多功能都可以base on呢個機制上實現

## TCP 長連接與短連接
這兩個是TCP的使用方式
1. 短連接: 多次性進行連接發送訊息
多數用於WEB Server
如果一些服務長期需要與Client Side傳輸訊息, 那麼使用這種短連接的模式顯然是不恰當既, 浪費時間亦浪費資源
但如果是一些短時間內無需傳輸訊息的服務來說, 這種短連接模式會大大節省Server Side既資源, 例如WEB Server呢種Send完一個網頁過去Client Side, 而Client Side又唔會經常向Server Side存取資源既服務. 一般而言做WEB Server的人員都會採用呢種模式, 一但Client Side收到完整既網頁後, Client Side 同 Server Side之間就會立即斷開
2. 長連接: 保持C/S之間的連接, 進行多次數據傳輸
多數用於Game Server(LOL, CSGO...)
