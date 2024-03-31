#include <stdio.h>

struct Rectangle /* here just a define, so that not consuming any memory */
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r; /* here will occupying memory, because here we create a variable of Rectangle type */ 
    /*
        int length, int = 4 byte
        int breadth, int = 4 byte 

        so you can assume that occupying 4 * 2 byte memory
    */

    struct Rectangle r1 = {10, 5}; /* here is declare, and initialize */

    /* accessing struct Rectangle member, and modify member */
    r1.length = 15;
    r1.breadth = 10;

    printf("structure Rectangle size = %lu", sizeof r1);
    printf("r1 area = %d\n", r1.length * r1.breadth);

    return 0;
}