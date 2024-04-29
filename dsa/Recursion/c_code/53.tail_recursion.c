#include <stdio.h>

void recursion_func(int n)
{
   if (n > 0) {
      // no operation in calling phase, this recursion is called tail recursion
      recursion_func(n - 1); 
   }
}

int main()
{
   recursion_func(3);
   return 0;
}
