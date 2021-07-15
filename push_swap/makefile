# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 19:06:53 by nwakour           #+#    #+#              #
#    Updated: 2021/07/15 15:57:11 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: 		all fclean clean re

NAME			=	push_swap

SRCS			=	srcs/push_swap.c srcs/operations.c srcs/init_list.c srcs/dup.c srcs/algo.c srcs/parse.c

OBJS			=	${SRCS:.c=.o}

NAME_BONUS		=	checker

SRCS_BONUS		=	bonus/checker.c bonus/correct_op.c bonus/init_list.c bonus/parse.c

OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

CC				=	gcc

FLAGS           =	-Wall -Wextra -Werror 

RM				=	rm -f

INCL 			=	-I includes -L includes

LIBFLAGS 		= 	-I ./libft -L ./libft -L . ./libft/*.c 

LIBFT_PATH 		= 	./libft

all:			libft_all $(NAME) 

$(NAME):		$(OBJS)
					@$(CC) -o $(NAME) $(SRCS) $(INCLUDE) $(LIBFLAGS) $(FLAGS)
					@echo "push_swap was created successfully"
bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
					@$(CC) -o $(NAME_BONUS) $(SRCS_BONUS) $(INCLUDE) $(LIBFLAGS) $(FLAGS)
					@echo "Checker was created successfully"
clean:			libft_clean
				@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			libft_fclean clean
				@$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

libft_all:
				@make -C $(LIBFT_PATH) all
				@cp ./libft/libft.a libft.a

libft_clean:
				@make -C $(LIBFT_PATH) clean

libft_fclean:
				@make -C $(LIBFT_PATH) fclean
				@$(RM) libft.a
