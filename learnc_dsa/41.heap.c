#include <stdio.h>
#include <stdlib.h>

int main()
{

   /* Heap memory should be treated like a resource */

   int *p;

   p = (int *)malloc(5 * sizeof(int));

   p[0] = 100;
   p[1] = 200;
   p[2] = 300;
   p[3] = 400;
   p[4] = 500;

   for(int i = 0; i < 5; i++)
   {
      printf("p[%d]: %d\n", i, p[i]);
   }

   // if you don't use a heap memory, please delete it
   // if you don't delete it, it will be still belonging to your program, and cannot be used again, so it cause loss of memory, and the loss of memory is called as "MEMORY LEAK".
   // If you do this many in program, then at one stage, the heap memory may be full.
   free(p);
   p = NULL;

   return 0;
}
