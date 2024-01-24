#include <stdio.h>

int main()
{
    int nc = 0;
    int ch;
    while((ch = getchar()) != EOF)
    {
        if(ch == '\n') 
        {
            nc++;
        }

        if(ch == 'e') {
            printf("line = %d\n", nc);
            return 0;
        }
    }
    return 0;
}