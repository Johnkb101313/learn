#include <stdio.h>

int main()
{
    int c, nspace, nother;

    nspace = nother = 0;

    int arr[10] = {0};

    while((c = getchar()) >= '0' && c <= '9' || c == ' ' || c == '\t' || c == '\n')
    {
        if(c >= '0' && c <= '9') 
        {
            arr[c - '0']++;
        } else if(c == ' ')
        {
            nspace++;
        } else {
            nother++;
        }
    }

    for(int i = 0; i < 10; i++)
        printf("'%d' = %d, ", i, arr[i]);

    printf("\nspace = %d", nspace);
    printf("\nother = %d", nother);
    putchar('\n');

    return 0;
}