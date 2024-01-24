1. lscpu: 查看cpu訊息
2. cat /proc/meminfo: 查看memory訊息
4. hostname: 查看主機名, 臨時設置主機名
    - hostname: 只查看主機名
    - hostname <name>: 臨時設置主機名
3. ifconfig(interface config): 查看已激活的網卡訊息, 臨時設置網卡配置
    使用ifconfig後看到的lo是Loopback的縮寫, 中文=回環測試接口, 專用於測試, ip永遠為127.0.0.1
    - ifconfig: 只查看已激活的網卡訊息
    - ifconfig <eth0> <ip>: 臨時設置網卡訊息
