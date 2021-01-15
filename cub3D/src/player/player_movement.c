/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:27 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/12 15:35:00 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			player_movement(t_all *all, t_player *player)
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		t;

	player->rotation = normalize_angle(player->rotation);
	if (player->turn != 0)
		player->rotation = player->rotation + (player->turn * 0.06);
	t = all->info.tile_size;
	y = all->map[(int)(player->y + (player->walk *
	sin(player->rotation) * 10)) / t][(int)player->x / t];
	y1 = all->map[(int)(player->y + (player->side_walk *
	sin(player->rotation + M_PI / 2) * 10)) / t][(int)player->x / t];
	x = all->map[(int)player->y / t]
	[(int)(player->x + (player->walk * cos(player->rotation) * 10)) / (t)];
	x1 = all->map[(int)player->y / t]
	[(int)(player->x + (player->side_walk *
	cos(player->rotation + M_PI / 2) * 10)) / t];
	if (y != '1' && y != '2' && y1 != '1' && y1 != '2')
		player->y = player->y + (player->walk * sin(player->rotation) * 4) +
					(player->side_walk * sin(player->rotation + M_PI / 2) * 2);
	if (x != '1' && x != '2' && x1 != '1' && x1 != '2')
		player->x = player->x + (player->walk * cos(player->rotation) * 4) +
					(player->side_walk * cos(player->rotation + M_PI / 2) * 2);
}
