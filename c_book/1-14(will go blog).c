#include <stdio.h>

int max(int * arr, int size) 
{
    int max = 0;
    for(int i = 0; i < size; i++, arr++)
        if(max < *arr)
            max = *arr;
    return max;
}

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
    int checklist[62] = {0};

    int dg_cmax = max(array, 10); /* digit count max */
    printf("max = %d\n", dg_cmax);
    for(int row = dg_cmax; row >= 0; row--) 
    {
        for(int n = 0; n <= 9; n++) 
        {
            if(row == array[n]) {
                printf("\033[%d;%dm   \033[0m ", 31 + (n % 7), 41 + (n % 7));
                checklist[n] = 1;
            } else if(checklist[n] == 1)
            {
                printf("\033[%d;%dm   \033[0m ", 31 + (n % 7), 41 + (n % 7));
            } else {
                printf("    ");
            }
        }
        printf("%d\n", row);
    }

    for(int i = 0; i <= 9; i++)
    {
        printf("--- ");
    }
    putchar('\n');
    putchar(' ');
    for(int i = 0; i <= 9; i++)
    {
        printf("%-4d", i);
    }
    putchar('\n');

    int azu_cmax = max(array + 10, 26); /* a-z upper case count max */
    printf("max = %d\n", azu_cmax);
    for(int row = azu_cmax; row >= 0; row--) 
    {
        for(int n = 10; n < 36; n++) 
        {
            if(row == array[n]) {
                printf("\033[%d;%dm   \033[0m ", 31 + (n % 7), 41 + (n % 7));
                checklist[n] = 1;
            } else if(checklist[n] == 1)
            {
                printf("\033[%d;%dm   \033[0m ", 31 + (n % 7), 41 + (n % 7));
            } else {
                printf("    ");
            }
        }
        printf("%d\n", row);
    }

    for(int i = 1; i <= 26; i++)
    {
        printf("--- ");
    }
    printf("\n ");
    for(int i = 0; i < 26; i++)
    {
        printf("%-4c", i + 65);
    }
    putchar('\n');

    int azl_cmax = max(array + 10, 26); /* a-z lower case count max */
    printf("max = %d\n", azl_cmax);
    for(int row = azl_cmax; row >= 0; row--) 
    {
        for(int n = 36; n < 62; n++) 
        {
            if(row == array[n]) {
                printf("\033[%d;%dm   \033[0m ", 31 + (n % 7), 41 + (n % 7));
                checklist[n] = 1;
            } else if(checklist[n] == 1)
            {
                printf("\033[%d;%dm   \033[0m ", 31 + (n % 7), 41 + (n % 7));
            } else {
                printf("    ");
            }
        }
        printf("%d\n", row);
    }

    for(int i = 1; i <= 26; i++)
    {
        printf("--- ");
    }
    printf("\n ");
    for(int i = 0; i < 26; i++)
    {
        printf("%-4c", i + 97);
    }
    putchar('\n');

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