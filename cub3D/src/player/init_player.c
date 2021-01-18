/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:54 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/17 15:50:14 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		coordinate_player(t_all *all, t_player *player)
{
	int		x;
	int		y;

	y = -1;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == 'N' || all->map[y][x] == 'S' ||
			all->map[y][x] == 'W' || all->map[y][x] == 'E')
			{
				player->x = all->info.tile_size * x + all->info.tile_size / 2;
				player->y = all->info.tile_size * y + all->info.tile_size / 2;
				player->position = all->map[y][x];
			}
		}
	}
}

static void		player_position(t_all *all, t_player *player)
{
	coordinate_player(all, player);
	if (player->position == 'N')
		player->rotation = 1.5 * M_PI;
	else if (player->position == 'W')
		player->rotation = M_PI;
	else if (player->position == 'E')
		player->rotation = 0;
	else if (player->position == 'S')
		player->rotation = 0.5 * M_PI;
}

void			init_player(t_all *all, t_player *player)
{
	player->radius = 5;
	player->turn = 0;
	player->walk = 0;
	player_position(all, player);
	player->walk_speed = all->info.tile_size / 15;
	if (player->walk_speed == 0)
		player->walk_speed = 1;
	player->turn_speed = 3 * (M_PI / 180);
}
