.text</em>

.global somaV

somaV:
    push    %ebp
    movl    %ebp,%esp
    movl    $0,%eax
    movl    8(%ebp),%edx
    movl    12(%ebp),%ecx
ciclo:cmp $0,%ecx
      jz    fim
      add   (%edx),%eax
      add   $4,%edx
      dec   %ecx
      jmp   ciclo
      
fim:pop   %ebp
ret</em>
