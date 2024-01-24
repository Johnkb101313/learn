#include <stdio.h>

int main()
{
   for(int celsius = 300; celsius >= 0; celsius -= 20)
   {
      printf("%3d %6.1f\n", celsius, 9.0 / 5.0 * celsius + 32);
   }

   return 0;
}
