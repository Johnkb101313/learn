section .data
   x dd 8.5
   y dd 3.14

section .text
global _start

_start:
   mov ebx,[x]
   add ebx,[y]

   mov eax,1
   mov ebx,0
   int 80h
