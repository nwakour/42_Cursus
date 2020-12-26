/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:48:03 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/20 13:04:59 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_all(t_all *all)
{
	t_mlx		mlx;
	t_player	player;
	t_draw		draw;
	t_info		info;

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
	all->orientation = '\0';
	all->map = NULL;
}

void	set_all(t_all *all)
{
	read_file(all);
	if (!ft_check_map(all, &all->orientation))
		return ;
	init_textute(all);
	player_move(all);
	cast_all_rays(all, all->ray);
}

int		update_all(t_all *all)
{
	all->mlx.img_p = mlx_new_image(all->mlx.mlx_p,
								WINDOW_WIDTH, WINDOW_HEIGHT);
	all->mlx.img_data = (int*)mlx_get_data_addr(all->mlx.img_p, &all->mlx.bits,
						&all->mlx.size, &all->mlx.endian);
	player_move(all);
	ft_putsprite(all, all->sprite, &all->player);
	cast_all_rays(all, all->ray);
	render_all(all);
	return (0);
}

void	render_all(t_all *all)
{
	projection_3d(all);
	draw_ceiling(all);
	draw_floor(all);
	drawmap(all);
	render_rays(all);
	draw_player(all);
	mlx_put_image_to_window(all->mlx.mlx_p, all->mlx.win_p,
							all->mlx.img_p, 0, 0);
}

int		main(void)
{
	t_all all;

	ft_init_all(&all);
	all.mlx.mlx_p = mlx_init();
	all.mlx.win_p = mlx_new_window(all.mlx.mlx_p, WINDOW_WIDTH,
					WINDOW_HEIGHT, "first");
	set_all(&all);
	update_all(&all);
	keys_set(&all);
	mlx_loop_hook(all.mlx.mlx_p, update_all, &all);
	mlx_loop(all.mlx.mlx_p);
	return (0);
}
