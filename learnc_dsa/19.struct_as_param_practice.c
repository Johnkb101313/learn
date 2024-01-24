#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
   int length;
   int breadth;
};

int get_rect_area(struct Rectangle r)
{
   return r.length * r.breadth;
}

void rect_infop(struct Rectangle r)
{
   printf("Rectangle Info:\n"
          "Length  - %d\n"
          "Breadth - %d\n", r.length, r.breadth);
}

void rect_scale(struct Rectangle *r, int n)
{
   r->length = r->length * n;
   r->breadth = r->breadth * n;
}

struct Rectangle * rect_new()
{
   return (struct Rectangle *)malloc(sizeof(struct Rectangle));
}

void rect_free(struct Rectangle *r)
{
   free(r);
}

int main()
{
   struct Rectangle *r;
   r = rect_new();
   r->length = 10; r->breadth = 5;

   rect_infop(*r);
   rect_scale(r, 2);
   rect_infop(*r);

   rect_free(r);
   return 0;
}
