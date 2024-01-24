#include <stdio.h>

struct Rectangle
{
   int length;
   int breadth;
};

int main()
{
   int *p1;
   char *p2;
   float *p3;
   double *p4;
   struct Rectangle *p5;

   // Whatever the data type of pointer is, poiner takes same amount of memory
   // TIPS: Earlier, pointer taking 4 bytes, But in latest compilers, they taking 8 bytes and 64bit machines
   printf("%lu\n", sizeof p1); // 8 bytes
   printf("%lu\n", sizeof p2); // 8 bytes
   printf("%lu\n", sizeof p3); // 8 bytes
   printf("%lu\n", sizeof p4); // 8 bytes
   printf("%lu\n", sizeof p5); // 8 bytes
   return 0;
}
