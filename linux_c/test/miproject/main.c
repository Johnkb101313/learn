#include <stdio.h>
#include "proj.h"

short i = 10;

int main()
{
   printf("<%s>: i = %d\n", __FUNCTION__, i);
   call_func();

   int a = 6;
   int i = 0;

   printf("%d\n", a = (i = 10, i = 100, i = 1000));
   printf("%lu", sizeof(int));

   int num;
   float f = 3.9;

   num = (int)f;

   printf("%d\n", ~1);

   return 0;
}
