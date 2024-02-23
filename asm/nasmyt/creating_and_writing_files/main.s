section .data
   path DB "/home/johnkb/learn/asm/nasmyt/creating_and_writing_files/1.txt",0
   toWrite DB "Hello World!",10,13
section .text

global _start

_start:
   MOV eax,5
   MOV ebx,path
   MOV ecx,101o
   MOV edx,700o
   INT 80h

   MOV ebx,eax
   MOV eax,4
   MOV ecx,toWrite
   MOV edx,14
   INT 80h

   MOV eax,1
   MOV ebx,0
   INT 80h
