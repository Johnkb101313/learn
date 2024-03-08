#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
   FILE *fp = fopen("tmp", "r");

   if (fp == NULL) {
      // perror("fopen");
      printf("%s", strerror(errno));
      return -1;
   }

   return 0;
}
