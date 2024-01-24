#include <stdio.h>

int add(int a, int b)
{
   return a + b;
}

int main()
{
   int result = 0;
   result = add(10, 100);
   printf("%d\n", result);
   return 0;
}
