*black-box abstraction 黑盒抽象*

[![black-box model](./black-box%20model.jpg)][1]

什麼是黑盒模型？

在科學、計算和工程中，黑盒子是一種設備、系統或物體，它可以產生有用的信息，但不會洩露任何有關其內部運作的信息。 其結論的解釋仍然不透明或“黑暗”。

而且通過這種模型我們可以方便地构建出更大型和複雜的程序

自己理解:
黑盒模型相當於programme 中的 function.
通過不同的 黑盒(function) 來組合一個大型的 programme.
一個重要的概念:黑盒(function) 裡面通常是抽象的, 越抽象, 通用性就越高
例如以下的 sum function 只能處理某個數的+1結果
```c
int sum(int a) {
    return a + 1;
}
```
但如果我們將當中的 1 抽象化 :
```c
int sum(int a ,int b) {
    return a + b;
}
```
現在這個 function 便可以處理某個數和某個數的相加值, 比以上第一個例子的 function 來得更通用.
這個 function 還可以更抽象嗎? 答案是可以, 因為當中還有一個具體的東西, 那就是 + 號
```c
#include <string>
int calc(int a ,const char * operator ,int b) {
    if(strcmp(operator, "+") == 0) {
        return a + b;
    } else if (strcmp(operator, "-") == 0) {
        return a - b;
    } else if (strcmp(operator, "*") == 0) {
        return a * b;
    } else if (strcmp(operator, "/") == 0) {
        return  a / b;
    // } else if ()...
}
```
現在這個 function 便可以解決兩個數之間四則運算.
現在通用性的確很高, 但其實要用起來會比較麻煩, 而且該 function 所做的事太多, 太混亂, 不明確, 所以不建議.
所以當一個黑盒太大, 太複雜顯然不是一件好事.

[1]: https://www.investopedia.com/terms/b/blackbox.asp