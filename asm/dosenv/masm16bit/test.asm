assume cs:codesg,ds:data

data segment
   db 'BaSiC'
   db 'MinIX'
data ends

codesg segment
main: mov ax,data
      mov ds,ax
      mov cx,5
      mov bx,0
      mov ax,0
s:    mov al,[bx]
      or al,100000b
      mov [bx],al
      inc bx
      loop s

codesg ends

end main
