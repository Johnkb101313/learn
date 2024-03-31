#include <stdio.h>

int main()
{
   int ch;
   int space = 0;
   int tab = 0;
   int line = 0;
   while((ch = getchar()) != EOF)
   {
      switch(ch)
      {
         case ' ':
            space++;
            break;

         case '\t':
            tab++;
            break;

         case '\n':
            line++;
            break;

         case 'e':
            printf("space = %d\n"
                   "tab = %d\n"
                   "line = %d\n", space, tab, line);
            return 0;
      }
   }
   return 0;
}
