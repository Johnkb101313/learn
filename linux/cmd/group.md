1. groupadd: 新增組
- -g --gid group's ID值。除非使用-o參數不然該值必須是唯一，不可相同。數值不可為負。預設為最小不得小於500而逐次增加。0~999傳統上是保留給系統帳號使用。

3. groupdel: 刪除組

3. gpasswd: 管理/etc/group(組訊息) 和 /etc/gshadow(組密碼)
現在很少人會特意設置組密碼, 原因:記起來麻煩
很多情況都是用來設置組成員, 增加組的成員或刪除組的成員
- a --add <user> <group>
- d --delete <user> <group>

查看組的訊息要去/etc/group

---
