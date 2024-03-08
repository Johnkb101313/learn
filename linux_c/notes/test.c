#include <stdio.h>
#include <errno.h>

// int main()
// {
//     char *string = "abc";
//     string[0] = 'x';
//
//     printf("%s", string);
//     return 0;
// }

int main()
{
   char num = errno;
   printf("%d\n", num);
   return 0;
}
