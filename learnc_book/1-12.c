#include <stdio.h>

int main()
{
    int c, lastc, space;

    lastc = space = 0;

    while((c = getchar()) != 'e')
    {
        if((lastc == ' ' || lastc == '\t') && c != ' ')
        {
            putchar('\n');
            putchar(c);
        } else if(c != ' ')
        {
            putchar(c);
        } else {
            space++;
        }

        lastc = c;
    }

    printf("%d\n", space);

    return 0;
}