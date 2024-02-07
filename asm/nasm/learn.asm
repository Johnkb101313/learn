start:
mov ax,0xb800
mov ds,ax

mov byte [0],'H'
mov byte [1],00001111b

mov byte [2],'e'
mov byte [3],00001111b

mov byte [4],'l'
mov byte [5],00001111b

mov byte [6],'l'
mov byte [7],00001111b

mov byte [8],'o'
mov byte [9],00001111b

mov byte [10],'w'
mov byte [11],00001111b

mov byte [12],'o'
mov byte [13],00001111b

mov byte [14],'r'
mov byte [15],00001111b

mov byte [16],'l'
mov byte [17],00001111b

mov byte [18],'d'
mov byte [19],00001111b

jmps:
jmp jmps

current:
times 510-(current-start) db 0

db 0x55, 0xaa
