/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:11 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/17 15:40:31 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define TEXTURE_NB 5
# define SUCCESS 0
# define ERROR -1
# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
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
	double			x;
	double			y;
	double			x_step;
	double			y_step;
	double			hit_x;
	double			hit_y;
	double			ver_hit_x;
	double			ver_hit_y;
	double			hor_hit_y;
	double			hor_hit_x;
	double			ver_hit;
	double			ray_angle;
	int				ver_wall;
	int				hor_wall;
	int				ray_down;
	int				ray_up;
	int				ray_right;
	int				ray_left;
	double			dist;
}					t_ray;

typedef struct		s_player
{
	double			x;
	double			y;
	int				radius;
	double			angle;
	int				turn;
	int				walk;
	int				side_walk;
	double			rotation;
	double			walk_speed;
	double			turn_speed;
	char			position;
}					t_player;

typedef struct		s_info
{
	t_list			*list;
	int				color_ceil;
	int				color_floor;
	int				fd;
	unsigned int	screenshoot;
	char			orientation;
	int				wall_strip_width;
	int				tile_size;
	int				rows_nb;
	int				cols_nb;
	int				window_width;
	int				window_height;
	int				real_width;
	int				real_height;
	double			num_rays;
	int				nb_sprite;
	double			fov_angle;
}					t_info;

typedef struct		s_tex
{
	char			*path;
	void			*tex_p;
	int				*img_data;
	int				bits;
	int				size;
	int				endian;
	int				height;
	int				width;
}					t_tex;

typedef struct		s_wall
{
	double			dist;
	double			dist_plane;
	int				s_height;
	int				top;
	int				bot;
}					t_wall;

typedef struct		s_sprite
{
	double			size;
	double			dist;
	double			x;
	double			y;
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
int					get_color(int *num_color, char *line, char *cmp);
int					path(char **dest, char *line, char *cmp, int n);
int					delete_empty_line_map(t_list **begin);
int					check_file_ext(char *line, char *ext);
int					nb_cloumn(t_list *node);
int					check_map(t_all *all, char *orientation);
void				delete_space_in_map(t_all *all, int column);
int					check_that_line_is_wall(char *line);
void				free_content(void *content);
void				init_tex(t_all *all);
void				check_args(t_all *all, int nb_arg, char **arg_array);
int					rows_cols_nb(t_all *all);
int					key_pressed(int key, void *param);
int					key_release(int key, void *param);
int					key_exit(void *param);
double				dist_to_point(double x1, double y1, double x2, double y2);
void				player_movement(t_all *all, t_player *player);
void				init_player(t_all *all, t_player *player);
void				cast_all_rays(t_all *all, t_player *player);
void				ray_horizontal(t_all *all, t_ray *ray, t_player *player);
void				ray_vertical(t_all *all, t_ray *ray, t_player *player);
void				projection_3d(t_all *all);
double				normalize_angle(double angle);
void				bmp_exporter(t_all *all, char *file_name);
void				mini_map(t_all *all, t_player *player, char **map);
void				put_sprite(t_all *all, t_player *player);
void				init_sprite(t_all *all, char **map);
int					handling_event(t_all *all);
int					game_loop(t_all *all);
int					collision(t_all *all, double y, double x);
int					close_window(int key, void *param);
void				draw_floor(t_all *all);
void				draw_ceiling(t_all *all);
int					correct_size(t_all *all);

#endif
