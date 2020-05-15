; mathlib.s
; Justin Ngo
; jmn4fms
; 3/30/20
;
; Purpose: The file will contain two subroutines, a product function and a power function
;          The product function is implemented iteratively with addition
;          The power function is implemented recursively with multiplication

    global product
    global power

    section .text

; _product
; @param1 first operand (repeatedly added to mimic multiplication)
; @param2 second operand (counter for iteration)
; @return = product of two params

product:
    push    rbp
    mov     rbp, rsp
    mov     DWORD [rbp-20], edi
    mov     DWORD [rbp-24], esi
    mov     DWORD [rbp-4], 0
    mov     DWORD [rbp-8], 0

product_loop:
    mov     eax, DWORD [rbp-8]
    cmp     eax, DWORD [rbp-24]
    jge     product_endloop
    mov     eax, DWORD [rbp-20]
    add     DWORD [rbp-4], eax
    add     DWORD [rbp-8], 1
    jmp     product_loop

product_endloop:
    mov     eax, DWORD [rbp-4]
    pop     rbp
    ret

; _power
; @base = first operand (repeatedly multiplied to mimic exponent)
; @power = second operand (decremented each recursive call)
; @return = base to the power of power


power:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD [rbp-4], edi
        mov     DWORD [rbp-8], esi
        cmp     DWORD [rbp-8], 0
        je      power_recursive
        mov     eax, DWORD [rbp-8]
        lea     edx, [rax-1]
        mov     eax, DWORD [rbp-4]
        mov     esi, edx
        mov     edi, eax
        call    power
        imul    eax, DWORD [rbp-4]
        jmp     power_end

power_recursive:
        mov     eax, 1

power_end:
        leave
        ret
