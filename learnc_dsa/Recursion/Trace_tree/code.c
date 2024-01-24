#include <stdio.h>

void fun1(int n)
{
   if(n > 0)
   {
      printf("%d\n", n);
      fun1(n - 1);
   }
}

void fun2(int n)
{
   if(n > 0)
   {
      fun2(n - 1);
      printf("%d\n", n);
   }
}

int main()
{
   int a = 3;
   // fun1(a);
   fun2(a);

   return 0;
}
