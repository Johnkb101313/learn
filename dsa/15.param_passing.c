#include <stdio.h>
// Call by value
void swap_value(int a, int b)
{
   a += b;
   b = a - b;
   a = a - b;
}

// Call by address
void swap(int *a, int *b)
{
   *a += *b;
   *b = *a - *b;
   *a = *a - *b;
}
// Benefit:
// Call by address can indirectly modify actual paramter
// Call by adderss can get change more than one thing, but call by value function just return back one thing

// Call by reference (c++ only)
/*
void swap_value(int &a, int &b)
{
   a += b;
   b = a - b;
   a = a - b;
}
*/
// Conceptually, reference are nicknames, not a pointer, but compiler may implement them as a pointer
// this function "maybe" come to be inline function, it depend on compiler

int main()
{
   int a = 10, b = 20;

   swap(&a, &b);

   printf("a = %d\n", a);
   printf("b = %d\n", b);
   return 0;
}
