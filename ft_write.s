section .text
global ft_write
extern __errno_location

ft_write:
    mov rax, 1
    syscall
    cmp rax ,0
    jl .error
    ret

.error:
    neg rax
    mov r10, rax
    call __errno_location wrt ..plt
    mov [rax], r10d
    mov rax, -1
    ret
