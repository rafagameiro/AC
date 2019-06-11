.text

#eax - contei o vetor 1
#ecx - contei o length
#edx - contei o vetor 2

.global prodInt

prodInt:
    push    %ebp
    mov     %esp,%ebp
    movl    8(%ebp),%edx
    movl    $0,%edi
    movl    $0,%eax
    movl    12(%ebp),%ebx
    movl    16(%ebp),%ecx
    
ciclo: 
    cmp     $0,%ecx
    jz      fim_ciclo
    movl    (%ebx),%edi 
    imul    (%edx),%edi
    add     %edi,%eax
    add     $4,%ebx
    add     $4,%edx
    loop    ciclo 
    
fim_ciclo:
    pop     %ebp
ret    
