section .data
   pathname DB "/home/johnkb/learn/asm/nasmyt/open_reading_files/1.txt",0
section .text
global _start
_start:
   MOV eax,5
   MOV ebx,pathname
   MOV ecx,0
   INT 0x80

loop:
   JMP loop

   MOV eax,1
   MOV ebx,0
   INT 0x80
