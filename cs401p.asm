[org 0x0100]

jmp start

givenid db 2,3,4,1,5,6,7,8,9
smallest_odd db 0
result times 9 db 0
odd_found db 0

start:
mov si, 0
mov bl, 9
mov byte [odd_found], 0

find_odd:
mov al, [givenid + si]
test al, 1
jz next
mov byte [odd_found], 1
cmp al, bl
jge next
mov bl, al
mov [smallest_odd], bl

next:
inc si
cmp si, 9
jl find_odd
cmp byte [odd_found], 0
jne odd_case

even_case:
mov si, 0


add_zero:
mov al, [givenid + si]
mov [result + si], al
inc si
cmp si, 9
jl add_zero
jmp exit

odd_case:
mov si, 0
mov bh, bl

add_odd:
mov al, [givenid + si]
add al, bh
mov [result + si], al
inc si
cmp si, 9
jl add_odd

exit: 
mov ax, 4C00h
int 21h

                  =============================================================================================================================
  the above code is used
a)	Store the numeric part of given ID in an array of numbers in memory.
b)	Find the smallest odd number of given ID and store it in memory. 
c)	Add each numeric digit of given ID to the smallest odd number and store it in a 2nd array.

                  -------------------------------------------------command to run above code: --------------------------------------------------
mount d D://AssmSoft

d:

nasm cs401P.asm -o cs401P.com

afd cs401P.com

CMD > m2 ds:0103 

than press f2 untill you get your result
