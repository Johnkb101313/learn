#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
   int length;
   int breadth;
};

int main()
{
   // struct Rectangle r = { 10, 5 };
   // printf("%d\n", r.length);
   // printf("%d\n", r.breadth);

   // struct Rectangle *p = &r;
   // printf("%d\n", p->length);
   // printf("%d\n", p->breadth);
   struct Rectangle *p = NULL;
   p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
   p->length = 10;
   p->breadth = 5;

   printf("%lu\n", sizeof *p);
   printf("%d\n", p->length);
   printf("%d\n", p->breadth);

   free(p);
   return 0;
}
