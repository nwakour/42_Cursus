# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 19:06:53 by nwakour           #+#    #+#              #
#    Updated: 2021/06/26 16:55:54 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: 		all fclean clean re

NAME_SERVER				=	server

NAME_CLIENT				=	client

SRCS_SERVER				=	srcs/server.c srcs/utils.c srcs/utils2.c

SRCS_CLIENT				=	srcs/client.c srcs/utils.c srcs/utils2.c

OBJS_SERVER				= 	${SRCS_SERVER:.c=.o}

OBJS_CLIENT				= 	${SRCS_CLIENT:.c=.o}

NAME_SERVER_BONUS		=	server_bonus

NAME_CLIENT_BONUS		=	client_bonus

SRCS_SERVER_BONUS		=	bonus/server_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c

SRCS_CLIENT_BONUS		=	bonus/client_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c

OBJS_SERVER_BONUS		= 	${SRCS_SERVER_BONUS:.c=.o}

OBJS_CLIENT_BONUS		= 	${SRCS_CLIENT_BONUS:.c=.o}

CC				= 	gcc
FLAGS           =  -Wall -Wextra -Werror
RM				= 	rm -f

all:			$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER)
				@$(CC) -o $(NAME_SERVER) $(SRCS_SERVER) $(FLAGS)

$(NAME_CLIENT):	$(OBJS_CLIENT)
				@$(CC) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(FLAGS)

bonus:			$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS):	$(OBJS_SERVER_BONUS)
						@$(CC) -o $(NAME_SERVER_BONUS) $(SRCS_SERVER_BONUS) $(FLAGS)

$(NAME_CLIENT_BONUS):	$(OBJS_CLIENT_BONUS)
						@$(CC) -o $(NAME_CLIENT_BONUS) $(SRCS_CLIENT_BONUS) $(FLAGS)

clean:
				@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean:			clean
				@$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re:				fclean all
