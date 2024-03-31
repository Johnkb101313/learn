1. useradd: 增加用戶
- -u --uid UID: 指定user的id, 使用:
```bash
useradd -u 1005 backup # 創建了一個名為backup, uid為1005的用戶
```
uid規則:
    1. 必須為唯一id號, 意即不可以與現有的用戶的uid一樣
    2. 不可以小於等於999, 0-999 在傳統上是留給系統使用的
- -d --home-dir HOMEDIR: 指定user的home directory, 默認值為/home/<用戶名>
- -s --shell SHELL: 指定user所使用的SHELL(解釋器), 默認值為/bin/bash. /etc/shells記錄了有哪些shell可以用, 其中/sbin/nologin較為特別: 如果你給用戶指定了這個shell, 該用戶就會被禁止登入操作系統
- -g --gid 群組: 新帳號之基本組的名稱或 ID
- -G --groups 群組: 新帳號的附加組列表
- -m --create-home

無法自動新增家目錄原因:
https://blog.csdn.net/qq_40259620/article/details/124970751

2. userdel: 刪除用戶
- -r, --remove                  移除家目錄及 mail spool

---

3. id: 查看用戶的訊息

---

4. su - run a command with substitute user and group ID
-, -l, --login
   Start the shell as a login shell with an environment similar to a
   real login:

   •   clears all the environment variables except TERM and variables
       specified by --whitelist-environment

   •   initializes the environment variables HOME, SHELL, USER,
       LOGNAME, and PATH

   •   changes to the target user’s home directory

   •   sets argv[0] of the shell to '-' in order to make the shell a
       login shell
---

5. usermod: 修改用戶屬性(user modify)
- -u --uid
- -d --home
- -s --shell
- -G --groups
