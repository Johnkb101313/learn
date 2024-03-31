#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    char ch;
    int word = 0;
    int state;
    if(getchar() != ' ') {
        word++;
        state = IN;
    } else {
        state = OUT;
    }
    while((ch = getchar()) != '\n')
    {
        if(state == OUT) {
            if(ch != ' ') {
                word++;
                state = IN;
            }
        } else if(state == IN) {
            if(ch == ' ') {
                state = OUT;
            }
        }
    }

    printf("word = %d\n", word);
    return 0;
}