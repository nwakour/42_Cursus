/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:26 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/11 15:46:09 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_pressed(int key, void *param)
{
	t_all *all;

	all = (t_all*)param;
	if (key == UP_KEY)
		all->player.walk = 1;
	else if (key == DOWN_KEY)
		all->player.walk = -1;
	else if (key == RIGHT_KEY)
		all->player.side_walk = 1;
	else if (key == LEFT_KEY)
		all->player.side_walk = -1;
	else if (key == RIGHT_ARROW)
		all->player.turn = 1;
	else if (key == LEFT_ARROW)
		all->player.turn = -1;
	else if (key == ESP_KEY)
		exit(free_all(all, SUCCESS));
	return (0);
}

int		key_release(int key, void *param)
{
	t_all *all;

	all = (t_all*)param;
	if (key == UP_KEY || key == DOWN_KEY)
		all->player.walk = 0;
	else if (key == RIGHT_KEY || key == LEFT_KEY)
		all->player.side_walk = 0;
	else if (key == RIGHT_ARROW || key == LEFT_ARROW)
		all->player.turn = 0;
	return (0);
}

int		key_exit(void *param)
{
	t_all *all;

	all = (t_all*)param;
	exit(free_all(all, SUCCESS));
	return (0);
}

int		handling_event(t_all *all)
{
	mlx_hook(all->mlx.win_p, 2, 0, key_pressed, all);
	mlx_hook(all->mlx.win_p, 3, 0, key_release, all);
	mlx_hook(all->mlx.win_p, 17, 0L, key_exit, all);
	return (0);
}
