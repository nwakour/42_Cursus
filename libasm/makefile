# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 14:48:32 by nwakour           #+#    #+#              #
#    Updated: 2021/01/26 18:36:08 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libasm.a

CSRC = main.c
ASRC = ft_strlen.s\
		ft_write.s\
		ft_strcpy.s\
		ft_strcmp.s\
		ft_read.s\
		ft_strdup.s

AOBJ = $(ASRC:.s=.o)


CFLAGS = -Wall -Werror -Wextra
NFLAGS = -g -f macho64 -o
all: $(NAME)

$(NAME):
	nasm $(NFLAGS) ft_strlen.o ft_strlen.s
	nasm $(NFLAGS) ft_write.o ft_write.s
	nasm $(NFLAGS) ft_strcpy.o ft_strcpy.s
	nasm $(NFLAGS) ft_strcmp.o ft_strcmp.s
	nasm $(NFLAGS) ft_read.o ft_read.s
	nasm $(NFLAGS) ft_strdup.o ft_strdup.s
	ar rc $(NAME) $(AOBJ)
	ranlib $(NAME)
	gcc $(CFLAGS) $(NAME) $(CSRC)
	/bin/rm -f $(AOBJ)

clean:
	/bin/rm -f $(AOBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all