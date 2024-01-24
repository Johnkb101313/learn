#include <stdio.h>

int area(int length, int breadth)
{
   return length * breadth;
}

int peri(int length, int breadth)
{
   return 2 * (length + breadth);
}

int main()
{
   int length = 0, breadth = 0;

   printf("Enter Length and Breadth: ");
   scanf("%d %d", &length, &breadth);

   int a = area(length, breadth);

   int p = peri(length, breadth);

   printf("area: %d\n", a);
   printf("peri: %d\n", p);

   return 0;
}
