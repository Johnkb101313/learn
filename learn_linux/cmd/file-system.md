1. cd (change directory)
- cd: go current user home
- cd ~: go current user home directory
- cd ~<user>: go <user> home directory
- cd ~root: go root home directory

---

2. ls (list directory contents)
- ls -d <dir>: 顯示directory自身而不是其內容
- ls -a: show .file include . and ..
- ls -A: show .file not include . and ..
- ls -R: Recursive

---

3. mkdir
- mkdir -p <newdir>: 如果發現創建的dir的父目錄沒有會一同創建
```bash
mkdir /home/johnkb/voiddir/newdir # 如果沒有voiddir, newdir也不會創建, 返回錯誤值
mkdir -p /home/johnkb/voiddir/newdir # 如果沒有voiddir, 他也會一同創建, voiddir創建完成就會創建newdir, 該操作為成功操作
```

---

4. cp (copy file/directory)
cp 本身會預設override存在的同檔名, 取消此行為可以使用-i or --interactive
注意事項: -i --interactive 在cp命令中比 -f --force 優先度高, 我猜是因為cp預設行為是會直接override屬於系統行為, 而當用戶想override可以直接使用cp而不加任何東西, 而用戶想改變這個預設行為就必須使用-i去取消屬於用戶行為, 而在program上用戶行為往往大於program的預設行為, 這也符合logic.

cp 支持複制一個以上的源到目標, 參數項中的最後一個參數視為目標
