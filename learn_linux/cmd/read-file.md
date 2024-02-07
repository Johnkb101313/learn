1. less: 分屏閱讀工具

---

2. head, tail: 分別查看文件頭和尾
    - head -n <要查看的行數> <file>
    - tail -n <要查看的行數> <file>
    沒指定-n flag默認查看10行
    更方便的寫法:
    - head -<要查看的行數> <file>
    - tail -<要查看的行數> <file>
    example:
    - head -2 /etc/passwd #查看/etc/passwd文件的頭兩行
    - tail -2 /etc/passwd #查看/etc/passwd文件的尾兩行

---

3. grep (global regular expression print):查看文件內容是否符合regular expression, 如果符合就print
    - -i flag: 不區分大小寫搜索
    - -v flag: 取反搜索

---
