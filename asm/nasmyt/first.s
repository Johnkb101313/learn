section .data
section .text
global _start

_start:
   mov eax,1 ;when call the kernel, kernel will look at the eax register, if its value is 1 that will call sys_exit(), all the syscall listed in /usr/include/asm/unistd.h

   mov ebx,1 ;this is the argument of syscall, we are calling sys_exit here, so it mean sys_exit(1), There are six registers (ebx, ecx, edx, esi, edi, ebp)that store the arguments of the system call used.

   int 80h ;call kernel
