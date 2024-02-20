extern printf ;extern is tell nasm, this are external function that we are linking later(in case is linking by gcc)
extern exit

section .data
   msg DB "hello world!",0
   fmt DB "OUTPUT: %s",10,0

section .text
global main

main:
   PUSH msg
   PUSH fmt
   CALL printf
   PUSH 1
   CALL exit
