#include <stdio.h>

struct Rectangle
{
   int length;
   int breadth;
};

void init(struct Rectangle *r, int length, int breadth)
{
   r->length = length;
   r->breadth = breadth;
}

int area(struct Rectangle r)
{
   return r.length * r.breadth;
}

int peri(struct Rectangle r)
{
   return 2 * (r.length + r.breadth);
}

int main()
{
   struct Rectangle r = { 0, 0 };
   int l, d;

   printf("Enter Length and Breadth: ");
   scanf("%d %d", &l, &d);

   init(&r, l, d);

   int a = area(r);

   int p = peri(r);

   printf("area: %d\n", a);
   printf("peri: %d\n", p);

   return 0;
}
