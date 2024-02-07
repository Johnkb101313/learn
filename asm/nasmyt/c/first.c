#include <stdio.h>
#include <stdlib.h>

void func(){
   exit(1);
}

int main()
{
   func();
   printf("Hello world");
   exit(1);
}
