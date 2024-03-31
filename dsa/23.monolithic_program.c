#include <stdio.h>

int main()
{
   int length, breadth;
   length = breadth = 0;

   printf("Enter Length and Breadth: ");
   scanf("%d %d", &length, &breadth);

   int area = length * breadth;

   int peri = 2 * (length + breadth);

   printf("area: %d\n", area);
   printf("peri: %d\n", peri);

   return 0;
}
