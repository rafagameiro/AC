
EXIT = 1
WRITE = 4
LINUX_SYSCALL = 0x80
 
.data          # secao de dados (variaveis)
	msg:	.ascii    "Monte de Caparica!\n"
	len = . - msg      # len representa o tamanho do vetor
	cifra:	.word 	-1   
## quando submeter ao mooshak mantenha as linhas anteriores originais ##


.text           # secao de codigo
.global _start 
_start:
    mov     $len,%dl
    movl    $msg,%eax
    mov     $0,%bl
    mov     (cifra),%bh
ciclo:
    cmp     %bl,%dl
    jz      fim_ciclo
    movb    (%eax),%cl
    add     %bh,%cl
    cmp     $32,%cl
    jz      isSpace
    cmp     $65,%cl
    jl      getTrueValueUP
    cmp     $97,%cl
    jl      getTrueValue
    jmp     addCifra
    
addCifra:    
    add     %bh,(%eax)
    inc     %eax
    inc     %bl
    jmp     ciclo
    
isSpace:
    inc     %eax
    inc     %bl
    jmp     ciclo   
    
getTrueValue:
    cmp     $65,%cl
    jg      addCifra
    sub     $97,%cl
    add     $123,%cl
    add     %cl,(%eax)
    inc     %eax
    inc     %bl
    jmp     ciclo    
 
getTrueValueUP:
    sub     $65,%cl
    add     $91,%cl
    add     %cl,(%eax)
    inc     %eax
    inc     %bl
    jmp     ciclo  
 
 fim_ciclo:
## nao altere daqui para baixo ##
	movl $len,%edx
 	movl $msg,%ecx         
 	movl $1,%ebx
 	movl $WRITE,%eax      # pedir write ao sistema
 	int  $LINUX_SYSCALL   # chama o sistema

 	movl $0,%ebx
 	movl $EXIT,%eax       # pedir exit ao sistema
 	int  $LINUX_SYSCALL   # chama o sistema
 	
