# enum vs #define in c
why we use enum instead of #define: 
1. Enums can be declared in the local scope
2. Enums names are automatically initialized by the compiler

## Some Fact about enum
1. Two or more names can have same value
```c
enum point { x = 0, y = 0, z = 0 };
```
enum 的主要工作是把數字變成一個有意義的值和變成一個常量
因此以下情況都可以
```c
enum math { RoundAngle = 360, TriangleAngle = 180 }
```

2. We can assign values in any order. All unassigned names will get value as value of previous name + 1
```c
enum math { RoundAngle = 360, SomeValue, TriangleAngle = 180 }
// SomeValue equal to 361
```

3. Only integral values are allowed.
4. All enum constant must be unique in their scope.
