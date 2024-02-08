section .bss   ;block starting symbol (used for reserving space in memory)
   num RESB 3

section .data
   num2 RESB 3

section .text
global _start

_start:
   MOV ebx,num
   MOV eax,1
   INT 80h
