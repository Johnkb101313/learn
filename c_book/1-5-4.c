#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, nw, state;

    state = OUT;

    while((c = getchar()) != '\n')
    {
        if(c == ' ') {
            state = OUT;
        } else if(state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("word = %d\n", nw);
    return 0;
}