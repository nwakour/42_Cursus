#include "cub3d.h"

void ft_init_all(t_all *all)
{
	t_mlx mlx;
	t_player player;
	t_draw draw;
	t_info info;

	mlx.mlx_p = NULL;
	mlx.win_p = NULL;
	mlx.img_p = NULL;
	mlx.img_data = NULL;
	info.ceilling = 0;
	info.floor = 0;
	info.num_sprite = 0;
	info.res_height = 0;
	info.res_width = 0;
	info.save = 0;
	init_player(&player);
	init_draw(&draw);
	all->mlx = mlx;
	all->player = player;
	all->draw = draw;
	all->info = info;
	all->map = NULL;
}
void check_file(t_all *all, char *line)
{
	if (line[0] == 'R')
		read_resolution(line, &all->info);
	else if (line[0] == 'N' && line[1] == 'O')
		read_path(&line[2], all, TEX_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		read_path(&line[2], all, TEX_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		read_path(&line[2], all, TEX_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		 read_path(&line[2], all, TEX_EA);
	else if (line[0] == 'S')
		 read_path(&line[1], all, TEX_S);
	else if (line[0] == 'F')
		 all->info.floor = read_floor_ceiling(&line[1]);
	else if (line[0] == 'C')
		 all->info.ceilling = read_floor_ceiling(&line[1]);
}

void read_file(t_all *all)
{
	int fd;
	char *line;
	int i;
	int lines;

	line = NULL;
	lines = 0;
	fd = open("map.txt",O_RDONLY);
	if (fd < 0)
		return ;
	else
	{
		while ((i = get_next_line(fd, &line)) > 0 && lines != 8)
		{
			if (i == 1 && line[0] != '\0')
			{
				check_file(all, line);
				lines++;
			}
		}
		all->map = ft_read_map(fd);
	}
}

void set_all(t_all *all)
{
	read_file(all);
	//all->map = ft_read_map();
	if (!ft_check_map(all->map))
		return ;
	init_textute(all);
	player_move(all);
	cast_all_rays(all);
}

void update_all(t_all *all)
{
	player_move(all);
	cast_all_rays(all);

}

void render_all(t_all *all)
{
	all->mlx.img_p = mlx_new_image(all->mlx.mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT);
	all->mlx.img_data = (int*)mlx_get_data_addr(all->mlx.img_p, &all->mlx.bits, &all->mlx.size, &all->mlx.endian);
	projection_3d(all);
	drawmap(all);
	render_rays(all);
	draw_player(all);
	mlx_put_image_to_window(all->mlx.mlx_p, all->mlx.win_p, all->mlx.img_p, 0, 0);
}

int		main()
{
	t_all all;

	ft_init_all(&all);
	all.mlx.mlx_p = mlx_init();
	all.mlx.win_p = mlx_new_window(all.mlx.mlx_p, WINDOW_WIDTH, WINDOW_HEIGHT, "first");
	set_all(&all);
	update_all(&all);
	render_all(&all);
	mlx_key_hook(all.mlx.win_p, key_hook, &all.mlx);
	mlx_loop(all.mlx.mlx_p);
	return (0);
}
