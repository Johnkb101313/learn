#include <stdio.h>

void func_1()
{
   int a = 10;
}

int func_2()
{
   int a;
   a++;
   return a;
}

int main()
{
   func_1();
   printf("%d", func_2());

   return 0;
}
