/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:48:03 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/18 14:35:08 by nwakour          ###   ########.fr       */
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
	all->map = NULL;
}

void	set_all(t_all *all)
{
	read_file(all);
	if (!ft_check_map(all->map))
		return ;
	init_textute(all);
	player_move(all);
	init_sprite(all, 14, 7);
	cast_all_rays(all);
}

int		update_all(t_all *all)
{
	player_move(all);
	generete_sprite(all);
	cast_all_rays(all);
	render_all(all);
	return (0);
}

void	render_all(t_all *all)
{
	all->mlx.img_p = mlx_new_image(all->mlx.mlx_p,
								WINDOW_WIDTH, WINDOW_HEIGHT);
	all->mlx.img_data = (int*)mlx_get_data_addr(all->mlx.img_p, &all->mlx.bits,
						&all->mlx.size, &all->mlx.endian);
	projection_3d(all);
	drawmap(all);
	render_all_sprites(all);
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
