# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 11:36:03 by nwakour           #+#    #+#              #
#    Updated: 2021/07/14 11:48:00 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all fclean clean re

NAME =		libft.a

SRCS =		ft_bzero.c ft_strlen.c ft_calloc.c ft_strncmp.c ft_strdup.c ft_strjoin_free.c\
			ft_atoi.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_isalpha.c ft_strcutone.c\
			ft_isalnum.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_putchar_fd.c\
			ft_strlcat.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_strndup.c\
			ft_memmove.c ft_strchr.c ft_strrchr.c ft_split.c ft_struct_bezero.c ft_strjoin_char.c\
			ft_find_struct_list.c ft_struct_list.c ft_isstingdigit.c ft_straddone.c\
			ft_putstr_fd.c ft_putnbr_fd.c ft_memchr.c ft_strlcpy.c ft_split_ref.c\
			ft_putendl_fd.c ft_itoa.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_strjoin.c\
			ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_strcmp.c ft_lstclear_last.c\
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_atoi_err.c\
			ft_lstmap.c ft_lstsize.c get_next_line.c ft_array_char.c ft_isspace.c ft_atol.c\

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
				@$(CC) -c $(SRCS) $(FLAGS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all