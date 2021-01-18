/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:09 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/16 17:46:34 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_mlx(t_all *all)
{
	if (!(all->mlx.mlx_p = mlx_init()))
	{
		ft_putstr_fd("Error\nFailed to init mlx\n", 1);
		exit(free_all(all, ERROR));
	}
}

static void		init_info(t_all *all)
{
	all->info.wall_strip_width = 1;
	if (all->info.window_width < all->info.window_height)
		all->info.tile_size = (all->info.window_width / all->info.cols_nb);
	else
		all->info.tile_size = (all->info.window_height / all->info.cols_nb);
	if (all->info.tile_size == 0)
		all->info.tile_size = 4;
	all->info.num_rays = (all->info.window_width / all->info.wall_strip_width);
	all->info.fov_angle = (60 * (M_PI / 180));
}

static void		create_window(t_all *all)
{
	if (!all->info.screenshoot)
	{
		if (all->info.real_width < 100 || all->info.real_height < 100)
		{
			if (!(all->mlx.win_p = mlx_new_window(all->mlx.mlx_p,
				all->info.real_width, all->info.real_height, "Cub3D")))
			{
				ft_putstr_fd("Error\nFailed to open a window\n", 1);
				exit(free_all(all, ERROR));
			}
		}
		else
		{
			if (!(all->mlx.win_p = mlx_new_window(all->mlx.mlx_p,
			all->info.window_width, all->info.window_height, "Cub3D")))
			{
				ft_putstr_fd("Error\nFailed to open a window\n", 1);
				exit(free_all(all, ERROR));
			}
		}
	}
}

static int		set_all(t_all *all, int argc, char **argv)
{
	check_args(all, argc, argv);
	if ((all->info.fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\nfailure open file\n", 1);
		return (ERROR);
	}
	all->info.window_width = -1;
	all->info.window_height = -1;
	all->info.color_floor = -1;
	all->info.color_ceil = -1;
	if (parsing(all) == ERROR)
		return (ERROR);
	init_mlx(all);
	create_window(all);
	init_tex(all);
	init_info(all);
	init_player(all, &all->player);
	init_sprite(all, all->map);
	return (SUCCESS);
}

int				main(int argc, char **argv)
{
	t_all		all;

	ft_struct_bezero((void*)&all, sizeof(t_all));
	if (set_all(&all, argc, argv) == ERROR)
		return (ERROR);
	if (!all.info.screenshoot)
	{
		handling_event(&all);
		mlx_loop_hook(all.mlx.mlx_p, game_loop, &all);
		mlx_loop(all.mlx.mlx_p);
	}
	else
		game_loop(&all);
	return (free_all(&all, SUCCESS));
}
