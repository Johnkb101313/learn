;section .data
;   num DB 1
;   num2 DD 2
;   num3 DB 3
;
;section .text
;global _start
;
;_start:
;   MOV ebx,[num]
;   MOV ecx,[num2]
;   MOV edx,[num3]
;
;   MOV eax,1
;   INT 80h

section .data
   char DB 1,2,3,4

section .text
global _start

_start:
   MOV eax,1
   MOV bl,[char]
   MOV bh,[char+1]
   MOV cl,[char+2]
   MOV ch,[char+3]

   INT 80h
