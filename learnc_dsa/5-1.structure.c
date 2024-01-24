/* how and where can we use struct */

/* 
    1. complex number (a + bi)
    in complex number we will have a "real part" and "imaginary part"
    so we can define a struct as:
*/
struct Complex
{
    int real; // -- int = 4 byte
    int imag; // -- int = 4 byte
};
// size = 8 byte

/*
    2. student
*/
struct Student
{
    int roll; // -- int = 4 byte
    char name[25]; // -- char = 1 byte, 25b * 1b = 25 byte
    char dept[10]; // -- 10 byte
    char address[50]; // -- 50 byte
};
// size = 89 byte