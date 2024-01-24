#include <stdio.h>

// struct padding
struct Rectangle
{
   int length; // 4 byte
   int breadth; // 4 byte
   char x; // 1 byte
};
// tatol 9 byte, but the sizeof(struct Rectangle) is = 12 byte
// why? because of struct padding
// because cpu not read only 1 byte one time,
// cpu is read 1 word in one time
// 1 word is mean how many cpu can access memory in one cycle time


// #pragma pack(1)

struct abc
{
   char a;
   char b;
   int n;
}__attribute__((packed));

int main()
{
   struct Rectangle r1;

   printf("%lu\n", sizeof r1);
   printf("%lu\n", sizeof(struct abc));
   return 0;
}
