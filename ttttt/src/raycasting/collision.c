/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:47 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 18:35:22 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			collision(t_all *all, float y, float x)
{
	int		mapgridindexx;
	int		mapgridindexy;

	if (x < 0 || x > (all->info.cols_nb * all->info.tile_size) ||
	y < 0 || y > (all->info.rows_nb * all->info.tile_size))
	{
		return (1);
	}
	mapgridindexx = floor(x / (float)all->info.tile_size);
	mapgridindexy = floor(y / (float)all->info.tile_size);
	return (all->map[mapgridindexy][mapgridindexx] == '1' ||
			all->map[mapgridindexy][mapgridindexx] == ' ');
}

void		player_collision(t_all *all, float y, float x)
{
	int		mapgridindexx;
	int		mapgridindexy;

	if (x < 0 || x > (all->info.cols_nb * all->info.tile_size) ||
	y < 0 || y > (all->info.rows_nb * all->info.tile_size))
	{
		return ;
	}
	mapgridindexx = floor(x / (float)all->info.tile_size);
	mapgridindexy = floor(y / (float)all->info.tile_size);
	if (all->map[mapgridindexy][mapgridindexx] != '1' &&
		all->map[mapgridindexy][mapgridindexx] != '2')
	{
		all->player.x = x;
		all->player.y = y;
	}
}
