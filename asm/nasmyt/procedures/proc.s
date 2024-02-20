section .text
global _start

func:
   MOV ecx,0
   RET

addTwo:
   ADD eax,ebx
   CALL func
   RET

_start:
   MOV eax,4
   MOV ebx,1
   CALL addTwo
   MOV ebx,eax
   INT 80h
