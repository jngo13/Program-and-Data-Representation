; Parameter 1 is a pointer to the int array
; Parameter 2 is the left index in the array
; Parameter 3 is the right index in the array
; Return type is void
_mergeSort:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 32
    mov     QWORD [rbp-24], rdi
    mov     DWORD [rbp-28], esi
    mov     DWORD [rbp-32], edx
    mov     eax, DWORD [rbp-28]
    cmp     eax, DWORD [rbp-32]
    jge     mergeSort_end
    mov     edx, DWORD [rbp-28]
    mov     eax, DWORD [rbp-32]
    add     eax, edx
    mov     edx, eax
    shr     edx, 31
    add     eax, edx
    sar     eax, 1
    mov     DWORD [rbp-4], eax
    mov     edx, DWORD [rbp-4]
    mov     ecx, DWORD [rbp-28]
    mov     rax, QWORD [rbp-24]
    mov     esi, ecx
    mov     rdi, rax
    call    _mergeSort
    mov     eax, DWORD [rbp-4]
    lea     ecx, [rax+1]
    mov     edx, DWORD [rbp-32]
    mov     rax, QWORD [rbp-24]
    mov     esi, ecx
    mov     rdi, rax
    call    _mergeSort
    mov     ecx, DWORD [rbp-4]
    mov     edx, DWORD [rbp-32]
    mov     esi, DWORD [rbp-28]
    mov     rax, QWORD [rbp-24]
    mov     rdi, rax
    call    _merge
    
mergeSort_end:
    nop
    leave
    ret
