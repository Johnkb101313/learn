# 我的順序表 Sequential List 實現

源碼: c_code/sequential_list.c

## 順序表結構 :
```c
typedef struct {
	int *data; // 順序表本身(Array)
	unsigned int len; // 順序表的總容量
	unsigned int count; // 順序表現在所存儲的數據個數
} Seq_List;
```

## 順序表操作 :
- 插入操作 (順序表容量滿的時侯會嘗試調用sl_expand()來壙容順序表)
    ```c
    int sl_insert(Seq_List *list, int ele, unsigned int index);
    ```

    成功返回 0  
    失敗返回 [SL_ERROR_CODE](#相關巨集-)

- 壙容操作 
    ```c
    int sl_expand(Seq_List *list);
    ```

    成功返回 0  
    失敗返回 [SL_ERROR_CODE](#相關巨集-)

- 覆蓋操作 
    ```c
    int sl_erase(Seq_List *list, unsigned int index);
    ```

    成功返回 被刪的數據  
    失敗返回 [SL_ERROR_CODE](#相關巨集-)

- 初始化操作 
    ```c
    Seq_List *sl_init(unsigned int len, int init_ele[], unsigned int init_ele_count);
    ```

    成功返回 新的[Seq_List](#順序表結構-)指針  
    失敗返回 NULL

- 釋放操作 
    ```c
    void sl_free(Seq_List *list);
    ```
- 打印操作
    ```c
    // 打印順序表已被使用的空間
    void print_ele(Seq_List *list);
    // 打印順序表包括未被使用的空間
    void print_sl(Seq_List *list);
    ```

## 相關巨集 :
```c
#define SL_ERROR_CODE 1 /* 以下函數的失敗返回值:
                        * sl_insert
                        * sl_expand
                        * sl_erase
                        */
```
