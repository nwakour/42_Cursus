
#ifndef CUBE3D_H
# define CUBE3D_H

#define PI 3.14159265
#define TWO_PI 6.28318530
#define TILE_SIZE 64
#define MAP_NUM_ROWS 14
#define MAP_NUM_COLS 33
#define MINI_MAP 0.3
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define FOV_ANGLE (60 * (PI / 180))
#define NUM_RAYS WINDOW_WIDTH

#define TEXTURE_SIZE 512
# define TEXTURE_NB 5
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define TEX_S 4

#define NO 0
#define EA 1
#define SO 2
#define WE 3

#define UP_KEY 13
#define DOWN_KEY 1
#define RIGHT_KEY 2
#define LEFT_KEY 0
#define ESP_KEY 53
#define SPACE_KEY 49
#define SHIFT_KEY 257
#define ZERO_KEY 65438

#include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_mlx
{
	void *mlx_p;
	void *win_p;
	void *img_p;
	int *img_data;
	int bits;
	int size;
	int endian;
}				t_mlx;

typedef struct s_player
{
	float x;
	float y;
	float width;
	float height;
	int turn;
	int walk;
	float rotation;
	float walkspeed;
	float turnspeed;

}				t_player;

typedef struct s_ray
{
	float ray_angle;
	float wall_x;
	float wall_y;
	float dist;
	int hit_ver;
	int ray_up;
	int ray_down;
	int ray_left;
	int ray_right;
	int wall_hit;
	int ray_cord;
}				t_ray;

typedef struct s_draw
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int height;
	int width;
	int color;
}				t_draw;

typedef struct	s_tex
{
	char	*path;
	void	*tex_ptr;
	int		*img_data;
	int		width;
	int		height;
	int		bits;
	int		size;
	int		endian;
}				t_tex;

typedef struct	s_info
{
	int				res_width;
	int				res_height;
	int				floor;
	int				ceilling;
	int				save;
	int				num_sprite;
}				t_info;

typedef struct s_all
{
	t_mlx mlx;
	t_player player;
	t_ray ray[NUM_RAYS];
	t_draw draw;
	t_tex tex[TEXTURE_NB];
	t_info info;
	char **map;
}				t_all;

					/* LIBFT */
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isdigit(int c);
int	ft_atoi(const char *str);

					/* CUB3D */
void render_all(t_all *all);
void update_all(t_all *all);
void set_all(t_all *all);
void ft_init_all(t_all *all);
void read_file(t_all *all);
					/* CHECK_FILE */
void	read_path(char *str, t_all *all, int t);
int		read_floor_ceiling(char *str);
void	read_resolution(char *str, t_info *info);

					/* texture */
int	take_texture(t_mlx *mlx, t_tex *tex);
void	init_textute(t_all *all);
int put_texture(t_all *all, int i, int j, int wall_bot);
					/* COLLISION */
int ft_collision(t_all *all, float x, float y);

					/* DRAW */
void init_draw(t_draw *draw);
void projection_3d(t_all *all);
void drawblock(int *img_data, t_draw draw, int color);
void drawline(int *img_data, t_draw draw);

					/* KEY */
int key_hook(int key, void *param);
int key_press_hook(int c, t_all *all);

					/* MAP */
char **list_to_map(t_list **list, int x, int y);
char 	**ft_read_map(int fd);
int	ft_check_map(char **map);
void drawmap(t_all *all);

					/* MATH */
float normalize_angle(float angle);
float dist_points(float x1, float y1, float x2, float y2);
float rad_to_angle(float rad);

					/* PLAYER */
void	init_player(t_player *player);

void player_move(t_all *all);
void draw_player(t_all *all);

					/* RAYS */
void	cast_ray(t_all *all, float ray_angle, int ray_num);
void	cast_all_rays(t_all *all);
void render_rays(t_all *all);

#endif
