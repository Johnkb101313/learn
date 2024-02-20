extern test
extern exit

section .text
global main

main:
   PUSH 1
   PUSH 2
   CALL test
   PUSH eax ;c function return value will automatic storage at eax
   CALL exit
