
.PHONY: all clean fclean re

NAME = cub3D

CC = gcc

SRC_LIBFT = libft/get_next_line.c libft/ft_lstnew.c \
libft/ft_lstadd_back.c libft/ft_lstsize.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_strlen.c

SRC_CUB3D = src/collision.c src/cub3d.c src/draw.c src/key.c src/map.c src/math.c src/player.c src/rays.c src/check_file.c src/texture.c src/sprite.c

SRCS = ${SRC_CUB3D} ${SRC_LIBFT}

INCL = -Iincludes/

OBJS = ${SRCS:.c=.o}

NAME = Cub3D

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : ${OBJS}
		gcc  -g ${FLAGS} -I/usr/local/include -o$(NAME) ${OBJS} -L/usr/local/lib -lmlx -framework Opengl -framework APPKIT

.c.o : ${SRCS}
		gcc -g ${FLAGS} -c ${INCL} $< -o ${<:.c=.o}
clean :
		rm -f ${OBJS}

fclean : clean
		rm -f $(NAME)

re : fclean
		make all
