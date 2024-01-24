#include <stdio.h>
#include <stdlib.h>

void fun(int A[], int n)
{
   for(int i = 0; i < n; i++)
      A[i] = 0;

   putchar('\n');
}

int * array(int n)
{
  return (int *)malloc(n * sizeof(int));
}

int main()
{
   int A[5] = { 2, 4, 6, 8, 10 };
   fun(A, 5);
   for(int i = 0; i < 5; i++)
      printf("%d ", A[i]);

   putchar('\n');
   return 0;
}
