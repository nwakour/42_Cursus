# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 21:19:01 by nwakour           #+#    #+#              #
#    Updated: 2021/01/23 15:14:19 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

SRC = ft_bzero.c ft_strlen.c ft_calloc.c ft_strncmp.c ft_strdup.c\
	ft_atoi.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_isalpha.c\
	ft_isalnum.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_putchar_fd.c\
	ft_strlcat.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memcmp.c\
	ft_memmove.c ft_strchr.c ft_strrchr.c ft_split.c\
	ft_putstr_fd.c ft_putnbr_fd.c ft_memchr.c ft_strlcpy.c\
	ft_putendl_fd.c ft_itoa.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_strjoin.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c\
		ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c\
		ft_lstmap_bonus.c ft_lstsize_bonus.c\


OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:
	gcc $(CFLAGS) -c $(SRC_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all