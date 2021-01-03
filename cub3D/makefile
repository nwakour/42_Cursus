# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 19:06:53 by nwakour           #+#    #+#              #
#    Updated: 2021/01/03 16:21:38 by nwakour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = cub3D

CC = gcc

SRC_LIBFT = libft/ft_bzero.c libft/ft_strlen.c libft/ft_calloc.c libft/ft_strncmp.c libft/ft_strdup.c\
	libft/ft_atoi.c libft/ft_isdigit.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_isalpha.c\
	libft/ft_isalnum.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strnstr.c libft/ft_putchar_fd.c\
	libft/ft_strlcat.c libft/ft_memset.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memcmp.c\
	libft/ft_memmove.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_split.c libft/ft_struct_bezero.c libft/ft_find_struct_list.c libft/ft_struct_list.c\
	libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_memchr.c libft/ft_strlcpy.c\
	libft/ft_putendl_fd.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_strjoin.c\
	libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_strcmp.c\
	libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_list_remove_one_if.c\
	libft/ft_lstmap.c libft/ft_lstsize.c libft/get_next_line.c libft/ft_array_char.c libft/ft_isspace.c\

SRC_CUB3D =	src/cub3d.c\
			src/game_loop.c\
			src/event.c\
			src/mini_map.c\
			src/texture/init_tex.c\
			src/parsing/check_args.c\
			src/parsing/free_all.c\
			src/math.c\
			src/parsing/parsing.c\
			src/utile.c\
			src/parsing/get_window_size.c\
			src/parsing/get_image_path.c\
			src/parsing/get_color.c\
			src/parsing/check_map.c\
			src/player/player_movement.c\
			src/raycasting/collision.c\
			src/player/init_player.c\
			src/raycasting/cast_all_rays.c\
			src/texture/draw_ceiling_and_floor.c\
			src/raycasting/ray_horizontal.c\
			src/raycasting/ray_vertical.c\
			src/raycasting/projection_3d.c\
			src/bmp_exporter.c\
			src/sprite/init_sprite.c\
			src/sprite/sprite.c\
			src/sprite/sprite_utile.c\
			src/parsing/parsing_utile.c\

SRCS = ${SRC_CUB3D} ${SRC_LIBFT}

INCL = -Iincludes/

OBJS = ${SRCS:.c=.o}

NAME = Cub3D

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${OBJS}
		gcc -g ${FLAGS} -I/usr/local/include -o$(NAME) ${OBJS} -L/usr/local/lib -lmlx -framework Opengl -framework APPKIT

.c.o : ${SRCS}
		gcc -g ${FLAGS} -c ${INCL} $< -o ${<:.c=.o}
clean :
		rm -f ${OBJS}

fclean : clean
		rm -f $(NAME)

re : fclean
		make all
