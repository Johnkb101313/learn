#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
   double fahr = 0,
          celsius = 0;

   int lower = LOWER,
       upper = UPPER,
       step = STEP;

   while(lower <= upper)
   {
      // because 5 / 9 will be int / int, 小數會舍進 最後會 5 / 9 = 0.555... 變成 5 / 9 = 0
      // but 5.0 / 9.0 will be float / float, 小數正常 = 5.0 / 9.0 = 0.55555...

      celsius = lower;

      fahr = (9.0 / 5.0) * celsius + 32;

      printf("%3.0f %6.1f\n", celsius, fahr);

      lower += step;
   }

   return 0;
}
