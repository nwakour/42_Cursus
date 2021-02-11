section .text
    	global _ft_strdup
		extern _ft_strlen
		extern _ft_strcpy
		extern _malloc

_ft_strdup:
	push rdi
	call _ft_strlen
	inc rax
	mov rdi, rax
	call _malloc
	pop rsi
	cmp rax, 0
	je error
	mov rdi, rax
	call _ft_strcpy
	ret
error:
	mov rax, 0
	ret
