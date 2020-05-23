section .text
    global main

main:
    push rbp
    mov rbp, rsp
    sub rsp, 3

    xor rax, rax
    xor rdi, rdi
    lea rsi, [rsp]
    mov rdx, 3
    syscall

    mov al, [rsp + 2]
    add al, [rsp]
    sub rax, 60h

    mov bl, 0Ah
    cmp al, bl
    jl one
    div bl
    add al, 30h
    add ah, 30h
    mov [rsp + 1], ah
    mov [rsp], al
    mov rdx, 2
    jmp print
one:
    add rax, 30h
    mov [rsp], al
    mov rdx, 1
print:
    mov rdi, 1
    mov rax, rdi
    syscall

    xor rax, rax
    mov rsp, rbp
    pop rbp
    ret