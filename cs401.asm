[org 0x0100]
jmp start

givenid db 2,1,3,4,5,6,7,8,9
sum dw 0
result db 9

start:
mov ax, 0
mov si, 0
calculation_sum:
mov al, [givenid + si]
add ah, al
inc si
cmp si, 9
jl calculation_sum

mov [sum], ah

mov si, 0
mov bl, ah

subtract_loop:
mov al, [givenid + si]
mov bh, bl
sub bh, al
mov [result + si],bl
inc si
cmp si, 9
jl subtract_loop

mov ax, 4c00h
int 21h
