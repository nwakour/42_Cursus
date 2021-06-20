section		.text
			global	_ft_strcmp
_ft_strcmp:
			mov		rax, -1
			mov		rcx, 0
			mov		rbx, 0

loop:
			inc		rax
			movzx	rcx, byte [rdi + rax]
			movzx	rbx, byte [rsi + rax]
			cmp		rcx, rbx
			jne		return
			cmp		rcx, 0
			je		return
			cmp		rbx, 0
			je		return
			jmp		loop
return:
			sub		rcx, rbx
			mov		rax, rcx
			ret