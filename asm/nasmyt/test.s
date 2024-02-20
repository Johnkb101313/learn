section .data
   list db 1,2,3,4
   list2 db 'UpPerLoWER'

section .text
global _start

_start:
   mov cl,0
   xor ebx,ebx
loop:
   add cl,[list+ebx]
   inc ebx
   cmp ebx,4
   jne loop

   xor ebx,ebx
   xor cl,cl
s:
   mov cl,[list2+ebx]
   and cl,0b11011111
   mov [list2+ebx],cl
   mov cl,[list2+ebx+5]
   or cl,0b00100000
   mov [list2+ebx+5],cl
   inc ebx
   cmp ebx,5
   jne s

   mov eax,1
   mov ebx,0
   int 80h
