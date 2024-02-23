section .text
global _start

addTwo:
   PUSH ebp
   MOV ebp,esp
   MOV eax,[ebp+8]
   ADD eax,[ebp+12]
   POP ebp
   RET

_start:
   PUSH 4
   PUSH 1
   CALL addTwo

   MOV ebx,eax
   MOV eax,1
   INT 80h
;why we need to passdata to function throught stack, because register are precious resource for us and we don't know how many data we will use
