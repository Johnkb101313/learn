1. alias: 給一些命令(不一定是命令)起別名
- alias <alia>='<cmd>/...'
- alias hn='hostname': 給hostname起別名為hn
- alias rm='rm -r': 給rm起別名為rm -r, 在rm時就可以把directory也可以刪掉
- alias: 例出當前可用的別名

2. unalias: 停用當前可用的別名
- unalias <alia>: alia為當前可用的別名
```bash
alias hn='hostname' # 給hostname起了別名hn
unalias hn # 給停用hn別名
```

想進行命令時臨時取消別名的使用, 可以在命令前加上backslach

```bash
\cp -r /boot /opt # 本次命令不會受alias命令影響
```

---

3. | (linux pipe) A pipe is a form of redirection in Linux used to connect the STDOUT of one command into the STDIN of a second command.
