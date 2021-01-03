/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:38:06 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/31 16:51:24 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	create_image(t_all *all)
{
	int			bpp;
	int			size_line;
	int			endian;

	if (!(all->mlx.img_p = mlx_new_image(all->mlx.mlx_p,
		all->info.window_width, all->info.window_height)))
	{
		ft_putstr_fd("Error\nFailed creating an image", 1);
		free_all(all, ERROR);
	}
	all->mlx.img_data = (int *)mlx_get_data_addr(all->mlx.img_p, &bpp,
						&size_line, &endian);
	all->info.size = size_line;
	if (!all->mlx.img_data)
	{
		ft_putstr_fd("Error\nFailed creating image data", 1);
		free_all(all, ERROR);
		exit(ERROR);
	}
}

static void		render_all(t_all *all)
{
	draw_ceiling(all);
	draw_floor(all);
	projection_3d(all);
	put_sprite(all, &all->player);
	mini_map(all, &all->player, all->map);
}

static void		update_all(t_all *all)
{
	create_image(all);
	player_movement(all, &all->player);
	cast_all_rays(all, &all->player);
	render_all(all);
}

int				game_loop(t_all *all)
{
	update_all(all);
	if (all->info.screenshoot)
		bmp_exporter(all, "my_screenshoot.bmp");
	else
	{
		mlx_put_image_to_window(all->mlx.mlx_p,
								all->mlx.win_p, all->mlx.img_p, 0, 0);
		mlx_destroy_image(all->mlx.mlx_p, all->mlx.img_p);
		all->mlx.img_p = 0;
	}
	return (SUCCESS);
}
