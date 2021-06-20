# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 19:06:53 by nwakour           #+#    #+#              #
#    Updated: 2021/06/18 14:29:58 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = push_swap

CC = gcc

SRC_LIBFT = libft/ft_bzero.c libft/ft_strlen.c libft/ft_calloc.c libft/ft_strncmp.c libft/ft_strdup.c\
	libft/ft_atoi.c libft/ft_isdigit.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_isalpha.c\
	libft/ft_isalnum.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strnstr.c libft/ft_putchar_fd.c\
	libft/ft_strlcat.c libft/ft_memset.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memcmp.c\
	libft/ft_memmove.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_split.c libft/ft_struct_bezero.c\
	libft/ft_find_struct_list.c libft/ft_struct_list.c libft/ft_split_ref.c libft/ft_strndup.c libft/ft_straddone.c\
	libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_memchr.c libft/ft_strcutone.c libft/ft_strlcpy.c\
	libft/ft_putendl_fd.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_strjoin.c\
	libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_strcmp.c libft/ft_lstclear_last.c\
	libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstclear_one_if.c\
	libft/ft_lstmap.c libft/ft_lstsize.c libft/get_next_line.c libft/ft_array_char.c libft/ft_isspace.c libft/ft_isstingdigit.c libft/ft_atol.c\

SRC_SHELL =	push_swap.c operations.c show_stack.c correct_op.c algo.c

SRCS = ${SRC_SHELL} ${SRC_LIBFT}

INCL = -Iincludes/

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${OBJS}
		gcc -g -fsanitize=address ${FLAGS} -o $(NAME) ${OBJS}

.c.o : ${SRCS}
		gcc -g -fsanitize=address ${FLAGS} -c ${INCL} $< -o ${<:.c=.o}
clean :
		rm -f ${OBJS}

fclean : clean
		rm -f $(NAME)

re : fclean
		make all
