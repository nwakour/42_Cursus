#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 21:19:01 by nwakour           #+#    #+#              #
#    Updated: 2019/10/18 21:21:05 by nwakour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

NAME = libftprintf.a

SRC = ft_printf.c ft_printfc.c ft_printfs.c ft_printfd.c ft_printfu.c ft_printfx.c ft_printfp.c ft_structflags.c\
	ft_printfs2.c ft_printfd2.c ft_printfu2.c ft_printfx2.c ft_strlen.c ft_itoa.c ft_putnbr.c ft_putstrnb.c ft_alloc_char.c\
	ft_strdup.c ft_hexaconv.c ft_strrev.c ft_strjoin.c ft_printfpurs.c ft_printfpurs2.c ft_free_return.c ft_putchar.c ft_putstr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
