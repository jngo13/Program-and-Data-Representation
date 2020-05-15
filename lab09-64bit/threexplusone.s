; threexplusone.s
; Justin Ngo
; jmn4fms
; 4/7/20

; Purpose: The file contains the implementation of the function
; threexplusone, which compute the number of steps it takes to
; reduce to 1 under the collatz conjecture
; collatz conjecture:
;   odd: 3x+1
;   even: x/2

; Optimization:
;   use and to find the remainder
;   use shr instead to divide by 2
;   use bit shift for multiplication/ division
;   store the paramter in rdi


    global threexplusone

    section .text

threexplusone:
    xor rax, rax
    cmp rdi, 1              ;checks if value in rdi is == 1
    je exit                 ;jumps and exits the program
    mov r8, rdi             ;moves rdi into r8 register
    and r8, 0x1
    cmp r8, 0
    je even                 ;if value is even jump to even
    jne odd                 ;if the value is odd jump to odd

exit:
    ret

even:
    shr rdi, 1              ;divide by 2
    call threexplusone     ;recursive call
    inc rax
    ret

odd:
    lea rdi, [3*rdi+1]      ;3x+1
    call threexplusone     ;recursive call
    inc rax
    ret
