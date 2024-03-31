#include <stdio.h>

int main()
{
    int ch;
    int lastc = 0;
    while((ch = getchar()) != '\n')
    {
        // i think the mind set is:
        // what time should print
        if(ch != ' ' || lastc != ' ') 
        {
            putchar(ch);
        }
        lastc = ch;
    }
    return 0;
}