section .bss ;.bss vs .data section: https://www.youtube.com/watch?v=JTkXmrLtV_w&t=24s
   buffer RESB 1024

section .text
   path DB "/home/johnkb/learn/asm/nasmyt/open_reading_files/1.txt",0,"testing"
   path2 DB "/home/johnkb/learn/asm/nasmyt/open_reading_files/2.txt",0

global _start
_start:
   MOV eax,5
   MOV ebx,path
   MOV ecx,0
   INT 80h

   MOV eax,5
   MOV ebx,path2
   MOV ecx,0
   INT 80h

   ;MOV ebx,eax
   ;MOV eax,3
   ;MOV ecx,buffer
   ;MOV edx,1024
   ;INT 80h

   MOV eax,1
   MOV ebx,0
   INT 80h
