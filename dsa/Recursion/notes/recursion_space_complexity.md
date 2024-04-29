```c
void fun1(n)
{
    if (n > 0) {
        fun1(n - 1);
        printf("%d\n", n);
    }
}

int main()
{
    int x = 3;
    fun1(x);

    return 0;
}
```

In this case:
call n + 1 time function, in this case is x = 3,And the last time call it will be:
```c
if (0 > 0) {}
```
, so it totally call 3 + 1 time fun1 function

So leaving the main function, that consuming 4 stack frame(activation record), so recursion is consuming stack space

Space Complexity: n+1 -take-degree-> O(n) stack frame

實際情況需要根據你消耗了多少 stack frame 來判斷你的 recursion Space Complexity
