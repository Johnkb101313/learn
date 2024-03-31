#include <stdio.h>

int main()
{
    int ch;
    while((ch = getchar()) != '\n') 
    {
        switch(ch)
        {
            case '\t':
                printf("\\t");
                break;
            case '\b':
                printf("\\b");
                break;
            default:
                putchar(ch);
        }
    }
    return 0;
}