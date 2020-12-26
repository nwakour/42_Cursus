
INC=%%%%

RM	= rm -f

INCLIB=$(INC)./minilibx-linux/lib

CC = gcc -g -fsanitize=address -Wall -Wextra -Werror -I./include/

CFLAGS= -I$(INC) -O3 -I../minilibx-linux

NAME= cub3D

SRC	=	./src/main.c\
		./src/utile/event.c\
		./src/utile/init_global_variable.c\
		./src/utile/mini_map.c\
		./src/utile/load_ptr_textures_in_array.c\
		./src/utile/normalize_angle.c\
		./src/utile/check_argument.c\
		./src/utile/free_all.c\
		./src/utile/distance_between_points.c\
		./src/parsing/parsing.c\
		./src/parsing/utile.c\
		./src/parsing/get_window_size.c\
		./src/parsing/get_image_path.c\
		./src/parsing/get_color.c\
		./src/parsing/check_character_map_utile.c\
		./src/parsing/check_character_map.c\
		./src/parsing/get_fd.c\
		./src/playerMovement/player_movement.c\
		./src/playerMovement/has_wall_at.c\
		./src/playerMovement/init_player.c\
		./src/cast_All_Rays/cast_all_rays.c\
		./src/cast_All_Rays/draw_ceiling_and_floor.c\
		./src/cast_All_Rays/ray_horizontal.c\
		./src/cast_All_Rays/ray_vertical.c\
		./src/cast_All_Rays/render_3d_projection.c\
		./src/screenshot/bmp_exporter.c\
		./src/sprite/init_sprite.c\
		./src/sprite/init_sprite_utile.c\
		./src/sprite/sprite.c\
		./src/sprite/sprite_utile1.c\
		./src/sprite/sprite_utile2.c\
		./src/parsing/parsing_utile.c\

OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	make bonus -C ./libft
	$(CC) -o $(NAME) $(OBJ) -L./libft -lft -L./minilibx-linux/ -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean	:
	make clean -C ./libft
	rm -f $(NAME) $(OBJ)

fclean:	clean
	make fclean -C ./libft
	$(RM) $(NAME)

re	: clean all
