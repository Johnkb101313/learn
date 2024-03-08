#include <stdio.h>
#include <stdbool.h>

#define MAX(a, b) ({ \
                     typeof(a) _a = a;\
                     typeof(b) _b = b;\
                     _a > _b;\
                   })

#define PI 3.14
#define MATH PI
#define INC(z) ({if (z > 1) z;})

// int test(int (* callback_function)())
// {
//    int callback_value = callback_function();
//
//    return callback_value + 10;
// }

int give_value()
{
   printf("calling me\n");
   static int a = 20;
   a++;
   return a;
}

int main()
{
   __auto_type a = 10;

   // typeof is more flexible than __auto_type; however, the principal use case for typeof is in variable declarations with initialization, which is exactly what __auto_type handles.
   printf("%d\n", a);

   __auto_type t = 0;

   printf("%d\n", MAX(t = give_value(), 20));

   int z = 290;

   auto int eax = 10;

   printf("%d", ({z + 1;}));

   return 0;
}
