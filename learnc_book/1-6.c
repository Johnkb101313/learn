#include <stdio.h>

int main()
{
   // We need to recive EOF -1 0xffffffff, so we must use int datatype to save a value from getchar;
   int c;

   // c = getchar() != EOF, != 優先度更高所以 c = getchar()必須使用括號包起來, 以下是正確示範
   // (c = getchar()) != EOF 等於 c != EOF
   while((c = getchar()) != EOF)
   {
      putchar(c);
   }
}
