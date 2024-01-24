struct Array
{
   int A[5];
   int length;
};

// Call by value
void fun(struct Array arr1)
{
}
// 如果結構體中包含array, 結構體依舊能夠以value的型式傳遞給function
// array不能以value的型式傳遞的原因是actual parameter的array copy給formal parameter, 如果那個array很大就需要較多的時間, 所以C不想支持
// 而為甚麼struct可以, 原因是迫不得已, 詳細原因暫時未知, 估計是C設計原因, 個人估計是結構體用途廣, 有時會用來calc, 而又想保証原數據的數據不會受到更改

// Call by address
void fun1(struct Array *arr1)
{
}

int main()
{
   struct Array arr = { { 1, 2, 3, 4, 5 }, 5 };

   fun(arr);

   return 0;
}
