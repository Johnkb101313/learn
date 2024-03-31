/*
 * why we need pointer ?
 * program utilize the main memory by dividing into three sections: stack heap code_section
 * program call directly access stack and code_section
 * The policy of a program is it will not directly access heap
 * Heap memory is external to the program
 * 1. If we want to access to heap memory, we need pointer
 * 2. pointer is useful for accessing the resources that are outside the program, heap is one thing, the other example such as hard disk file, keyboard, monitor...
 * 3. pointer also use for parameter passing
 * */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a = 10;
   int *p;
   p = &a;

   printf("*p = %d\n", *p); // 解引用既英文 dereferencing
   printf("p = %lu, a = %lu\n", sizeof p, sizeof a);

   /* accessing heap memory using pointer: */
   /* TIPS: whenever you declare it will be inside stack. */

   // First: we need to use a function name malloc to allocate memory in heap
   // Second: we need a pointer access heap memory, so we need to declare one pointer variable
   // Three: use a pointer varible to receive malloc's return void type pointer

   int *p1;
   p1 = (int *)malloc(5 * sizeof(int)); // when we call a malloc function, we need to #include <stdlib.h>

   p1[0]=10; p1[1]=15; p1[2]=14; p1[3]=21; p1[4]=31;

   for(int i = 0; i < 5; i++)
      printf("%d\n", p1[i]);

   /* also remember if you don't use the heap memory, you should deallocated it */
   /* if you are doing a small program, not go to deallocated it, it is not a problom, because when program end, the heap memory will automatically deleted it */
   free(p1);
   return 0;
}
