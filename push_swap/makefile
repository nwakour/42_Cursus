# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 19:06:53 by nwakour           #+#    #+#              #
#    Updated: 2021/07/11 20:28:31 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: 		all fclean clean re

NAME			=	push_swap

SRCS			=	srcs/push_swap.c srcs/operations.c srcs/show_stack.c srcs/init_list.c srcs/dup.c srcs/algo.c srcs/parse.c

OBJS			=	${SRCS:.c=.o}

NAME_BONUS		=	checker

SRCS_BONUS		=	bonus/checker.c bonus/correct_op.c bonus/init_list.c bonus/parse.c

OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

CC				=	gcc

FLAGS           =	-Wall -Wextra -Werror -fsanitize=address

RM				=	rm -f

INCL 			=	-Iincludes/

all:			$(NAME)

$(NAME):	$(OBJS)
				@$(CC) -o $(NAME) $(SRCS) $(FLAGS)
.c.o : ${SRCS}
				@$(CC) $(FLAGS) -c ${INCL} $< -o ${<:.c=.o}

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
						@$(CC) -o $(NAME_BONUS) $(SRCS_BONUS) $(FLAGS)
.c.o :			${SRCS_BONUS}
						@$(CC) $(FLAGS) -c ${INCL} $< -o ${<:.c=.o}

clean:
				@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				@$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all
