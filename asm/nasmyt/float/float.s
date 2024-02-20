section .data
   x dd 3.14
   y dd 8.5
section .text
global _start

_start:
   movss xmm0,[x]
   movss xmm1,[y]
   ;addss xmm0,xmm1
   ucomiss xmm0,xmm1
   jb less
   jmp end

less:
   mov ecx,1

end:
   mov eax,1
   mov ebx,0
   int 80h
