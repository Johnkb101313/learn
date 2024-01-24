#include <stdio.h>

int main()
{
    int c, nother = 0;
    // hash map ?
    int array[62] = {0}; /* index 0-9: digit 0-9 
                            index 10-35: English Alphabet upper case 
                            index 36-61: English Alphabet lower case */
    
    while((c = getchar()) != '^')
    {
        if(c >= '0' && c <= '9')
        {
            array[c - '0']++;
        } else if(c >= 'A' && c <= 'Z')
        {
            array[c - 55]++; /* 'A' ascii value tranform to array index for count */
        } else if(c >= 'a' && c <= 'z')
        {
            array[c - 61]++; /* 'a' ascii value tranform to array index for count */
        } else {
            nother++;
        }
    }

    /* print digit */
    for(int i = 0; i <= 9; i++)
    {
        printf("%-2d|", i);
        for(int n = 0; n < array[i]; n++)
        {
            putchar(' ');
        }
        printf("| %d\n", array[i]);
    }

    putchar('\n');

    /* print English Alphabet upper case  */
    for(int i = 10; i <= 35; i++)
    {
        printf("%-2c|", i + 55);
        for(int n = 0; n < array[i]; n++)
        {
            putchar(' ');
        }
        printf("| %d\n", array[i]);
    }

    putchar('\n');

    /* print English Alphabet upper case  */
    for(int i = 36; i <= 61; i++)
    {
        printf("%-2c|", i + 61);
        for(int n = 0; n < array[i]; n++)
        {
            putchar(' ');
        }
        printf("| %d\n", array[i]);
    }

    return 0;
}