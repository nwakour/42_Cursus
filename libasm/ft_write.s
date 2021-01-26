section     .text
            global _ft_write

_ft_write:
			mov rax, 0x2000004      ; System call write = 4
			syscall
			ret