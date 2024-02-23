section .bss
   buffer RESB 10
section .data
   path DB "/home/johnkb/learn/asm/nasmyt/lseek_with_files/1.txt"
section .text
global _start
_start:
   MOV eax,5
   MOV ebx,path
   MOV ecx,0
   INT 80h

   MOV ebx,eax
   MOV eax,19
   MOV ecx,20
   MOV edx,0
   INT 80h

   MOV eax,3
   MOV ecx,buffer
   MOV edx,10
   INT 80h

   MOV eax,1
   MOV ebx,0
   INT 80h
