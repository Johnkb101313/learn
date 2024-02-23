- Store information about employees - Name - Address - Hours Worked
    可以創建一個結構體
    ```c
    struct Employee
    {
        const unsigned char id; // id 可以防止重名
        const char[100] name;
        struct Address {};
        unsigned int hours_worked;
    };
    ```

- Add employees to the database
    maybe add a create Employee function?

- Update employees in the database
    因為員工的職位有所不同，有些員工的上班日子多，代表着更新相關員工在Database的資料會較頻密，所以可以將他們在Database的排序調高，縮短Search的過程，並更改其員工資料，該過程可以每日深夜時份自動進行，按照佢地的打卡次數頻率排序。
```c
    struct Employee
    {
        const unsigned char id;
        const char[100] name;
        struct Address {};
        int hours_worked;
        int update_time; // 此條目用來紀綠資料的更新次數，而且可以用來追蹤他們的打卡次數
    };
```

- Store all this information to a file
- Load and edit the database file
- Search the database by name, address, or hours
