/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:11 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 19:08:42 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define TEXTURE_NB 5
# define SUCCESS 0
# define ERROR -1
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define RIGHT_ARROW 2
# define LEFT_ARROW 0
# define SHIFT_KEY 257
# define ESP_KEY 53
# define MAX_VALUE 2147483647
# define MINI_MAP 0.3
# define WINDOW_WIDTH 2560
# define WINDOW_HEIGHT 1440
# define TEXTURE_NB 5
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4

typedef struct		s_ray
{
	float			x;
	float			y;
	float			x_step;
	float			y_step;
	float			hit_x;
	float			hit_y;
	float			ver_hit_x;
	float			ver_hit_y;
	float			hor_hit_y;
	float			hor_hit_x;
	float			ver_hit;
	float			ray_angle;
	int				ver_wall;
	int				hor_wall;
	int				ray_down;
	int				ray_up;
	int				ray_right;
	int				ray_left;
	float			dist;
}					t_ray;

typedef struct		s_player
{
	float			x;
	float			y;
	int				radius;
	float			angle;
	int				turn;
	int				walk;
	float			rotation;
	float			walk_speed;
	float			turn_speed;
	char			position;
	int				translation;
}					t_player;

typedef struct		s_info
{
	t_list			*list;
	int				color_ceil;
	int				color_floor;
	int				fd;
	unsigned int	screenshoot : 1;
	char			orientation;
	int				wall_strip_width;
	int				tile_size;
	int				rows_nb;
	int				cols_nb;
	int				window_width;
	int				window_height;
	float			num_rays;
	int				nb_sprite;
	float			fov_angle;
	int				size;
}					t_info;

typedef struct		s_tex
{
	char			*path;
	void			*tex_p;
	int				*img_data;
	float			*buffer;
	int				bits;
	int				size;
	int				endian;
	int				height;
	int				width;
}					t_tex;

typedef struct		s_wall
{
	float			dist;
	float			dist_plane;
	int				s_height;
	int				top;
	int				bot;
}					t_wall;

typedef struct		s_sprite
{
	float			dir_y;
	float			dir_x;
	float			plan_y;
	float			plan_x;
	float			size;
	float			distance;
	float			x;
	float			y;
	int				spritescreenx;
	int				start_y;
	int				end_y;
	int				start_x;
	int				end_x;
}					t_sprite;

typedef struct		s_mlx
{
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	int				*img_data;
	int				bits;
	int				size;
	int				endian;
}					t_mlx;

typedef struct		s_bmp
{
	char			byte_type[2];
	unsigned int	byte_size;
	unsigned int	byte_reserved;
	unsigned int	byte_offset;
	unsigned		header_size;
	int				image_width;
	int				image_height;
	unsigned short	color_planes;
	unsigned short	bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	int				bits_xpels_per_meter;
	int				bits_ypels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}					t_bmp;

typedef struct		s_all
{
	t_mlx			mlx;
	t_info			info;
	t_player		player;
	t_tex			tex[TEXTURE_NB];
	t_list			*l_ray;
	t_list			*l_sprite;
	t_ray			*ray;
	t_sprite		*sprite;
	char			**map;
}					t_all;

int					free_all(t_all *all, int ret);
int					parsing(t_all *all);
int					skip_number(char *str);
int					skip_space(char *str);
int					get_window_size(t_all *all, char *line);
t_list				*get_node(t_list **begin, char *search, int n);
int					get_color(int *num_color, char *line, char *cmp);
int					path(char **dest, char *line, char *cmp, int n);
int					delete_empty_line_map(t_list **begin);
int					check_file_ext(char *line, char *ext);
int					nb_cloumn(t_list *node);
int					check_character_around(char **map, int i, int j);
int					check_map(t_all *all, char *orientation);
void				delete_space_in_map(t_all *all, int column);
int					check_that_line_is_wall(char *line);
void				free_content_node(void *line);
void				init_tex(t_all *all);
void				check_args(t_all *all, int nb_arg, char **arg_array);
int					rows_cols_nb(t_info *info);
int					key_pressed(int key, void *param);
int					key_release(int key, void *param);
int					key_exit(void *param);
float				dist_to_point(float x1, float y1, float x2, float y2);
void				player_movement(t_all *all, t_player *player);
void				init_player(t_all *all, t_player *player);
void				cast_all_rays(t_all *all, t_player *player);
void				ray_horizontal(t_all *all, t_ray *ray, t_player *player);
void				ray_vertical(t_all *all, t_ray *ray, t_player *player);
void				projection_3d(t_all *all);
float				normalize_angle(float angle);
void				bmp_exporter(t_all *all, char *file_name);
void				mini_map(t_all *all, t_player *player, char **map);
void				put_sprite(t_all *all, t_player *player);
void				init_sprite(t_all *all, char **map, char player_position);
int					handling_event(t_all *all);
int					game_loop(t_all *all);
int					sprite_visible(t_all *all, t_player *player);
float				cal_angle(t_player *player, float x, float y);
void				get_start(t_all *all);
void				draw_sprite(t_all *all, float transformy);
void				put_tex(t_all *all, t_sprite *sprite, int x, int y);
int					collision(t_all *all, float y, float x);
int					close_window(int key, void *param);
void				draw_floor(t_all *all);
void				draw_ceiling(t_all *all);
void				player_collision(t_all *all, float y, float x);

#endif
