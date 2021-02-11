section .text
    	global _ft_atoi_base
		extern _ft_strlen
_ft_atoi_base:
				push rdi
				mov rdi, rsi
				call _ft_strlen
				pop rdi
				jmp check_base
				ret

check_base:
	cmp rax, 1
	jle zero_return
	mov rbx, -1
	jmp check_base_dup

check_base_dup:
	inc rbx
	cmp rbx, rax
	jge done
	mov cl, byte [rsi + rbx]
	cmp cl, 43
	je zero_return
	cmp cl, 45
	je zero_return
	mov rdx, -1
	jmp dup_loop

dup_loop:
	inc rdx
	cmp rdx, rax
	jge check_base_dup
	cmp rbx, rdx
	je dup_loop
	cmp cl, byte [rsi + rdx]
	je zero_return
	jmp dup_loop

done:
	mov rax, 1
	ret

zero_return:
	mov rax, 0
	ret
