/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:53:49 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/18 13:51:18 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_success(t_all *all)
{
	mlx_destroy_window(all->mlx.mlx_p, all->mlx.win_p);
	exit(0);
	return (1);
}

int		key_hook(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if ((key >= 0 && key <= 2) || key == 13)
	{
		key_press_hook(key, all);
		update_all(all);
		render_all(all);
	}
	return (0);
}

int		key_press_hook(int c, t_all *all)
{
	if (c == ESP_KEY)
		exit_success(all);
	if (c == UP_KEY)
		all->player.walk = +1;
	else if (c == DOWN_KEY)
		all->player.walk = -1;
	else if (c == RIGHT_KEY)
		all->player.turn = +1;
	else if (c == LEFT_KEY)
		all->player.turn = -1;
	return (0);
}

int		key_release_hook(int c, void *info)
{
	t_all	*all;

	all = (t_all*)info;
	if (c == UP_KEY)
		all->player.walk = 0;
	else if (c == DOWN_KEY)
		all->player.walk = 0;
	else if (c == RIGHT_KEY)
		all->player.turn = 0;
	else if (c == LEFT_KEY)
		all->player.turn = 0;
	return (0);
}

int		keys_set(t_all *all)
{
	mlx_hook(all->mlx.win_p, 2, 0, key_press_hook, all);
	mlx_hook(all->mlx.win_p, 3, 0, key_release_hook, all);
	mlx_hook(all->mlx.win_p, 17, 0, exit_success, all);
	return (0);
}
