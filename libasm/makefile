# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 14:48:32 by nwakour           #+#    #+#              #
#    Updated: 2021/05/29 16:14:24 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libasm.a

SRC = ft_strlen.s\
		ft_write.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_read.s\
		ft_strdup.s

ASM_COMPILER = nasm -f macho64

all:	$(NAME)

%o		:	%s
	$(ASM_COMPILER) $<

$(NAME) :	$(SRC:.s=.o)
	ar -rc  libasm.a $(SRC:.s=.o)
	ranlib libasm.a

clean:
		rm -f $(SRC:.s=.o)

fclean:	clean
		rm -f $(NAME) a.out

re:		fclean all
