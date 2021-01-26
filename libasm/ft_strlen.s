section     .text
            global _ft_strlen

_ft_strlen:
            mov  rax, -1            ;int i = -1;

loop:
            inc rax                   ;i++;
            cmp byte [rdi + rax], 0   ;if (str[i] != '\0')
            jne loop                  ;   loop;
            ret                       ;return (0);