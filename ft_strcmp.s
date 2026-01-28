section .text
global ft_strcmp

ft_strcmp:
    xor rcx, rcx

.loop:
    mov al, byte [rdi + rcx]
    mov dl, byte [rsi + rcx]
    cmp al, dl
    jne .diff
    cmp al, 0
    je .diff
    inc rcx
    jmp .loop

.diff:
    movzx rax, al
    movzx rdx, dl
    sub rax, rdx
    ret
