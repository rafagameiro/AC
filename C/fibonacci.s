.text

.global fibonacci

fibonacci:
    push    %ebp
    mov     %esp,%ebp
    mov     8(%ebp),%eax
    cmp     $0,%eax
    jz      fim
    cmp     $1,%eax
    jz      fim
    dec     %eax
    push    %eax
    add     4,%esp
    call    fibonacci
    
    
fim:
    pop     %ebp
ret   
