section .data
hello_world     db      "Hello World!",0x0a,0

section .text
global _main

_main:
mov rax, hello_world
call _write             ; call write fuction
mov rax, 0x2000001      ; System call number for exit = 1
mov rdi, 0              ; Exit success = 0
syscall       

_write:
call _strlen
mov rax, 0x2000004      ; System call write = 4
mov rdi, 1              ; Write to standard out = 1
syscall
ret                     ; return

_strlen:
push rax
mov rbx, 0

jmp _count

_count:
inc rax
inc rbx
mov cl, [rax]
cmp cl, 0
jne _count

pop rsi
mov rdx, rbx
ret