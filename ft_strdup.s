section .text
global ft_strdup
extern malloc
extern ft_strlen

ft_strdup:
    push rbx
    push r12

    mov r12, rdi
    call ft_strlen wrt ..plt
    mov rbx, rax
    
    lea rdi, [rax + 1]
    call malloc wrt ..plt
    
    cmp rax, 0
    je .end

    mov rdi, rax
    mov rsi, r12
    mov rcx, rbx
    inc rcx
    mov r12, rax

.copy:
    mov al, byte [rsi]
    mov byte [rdi], al
    inc rsi
    inc rdi
    dec rcx
    jnz .copy
    mov rax, r12
    ; return dest

.end:
    pop r12
    pop rbx
    ret
