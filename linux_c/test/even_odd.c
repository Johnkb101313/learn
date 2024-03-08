#include <stdio.h>

int main()
{
   int usr = 0;
   scanf("%d", &usr);

   // 0: even, 1: odd
   if (usr & 1)
      printf("is odd");
   else
      printf("is even");

   return 0;
}
