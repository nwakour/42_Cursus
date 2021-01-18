/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:27 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/16 16:37:51 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			y_move(t_player *player)
{
	player->y = player->y + (player->walk * sin(player->rotation)
		* player->walk_speed * 0.5) + (player->side_walk * sin(player->rotation
		+ M_PI / 2) * (player->walk_speed * 0.25));
}

void			x_move(t_player *player)
{
	player->x = player->x + (player->walk *
		cos(player->rotation) * player->walk_speed * 0.5) + (player->side_walk
		* cos(player->rotation + M_PI / 2) * (player->walk_speed * 0.25));
}

void			player_movement(t_all *all, t_player *player)
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		t;

	player->rotation = normalize_angle(player->rotation);
	if (player->turn != 0)
		player->rotation = player->rotation + player->turn * player->turn_speed;
	t = all->info.tile_size;
	y = all->map[(int)(player->y + (player->walk *
	sin(player->rotation) * (player->walk_speed))) / t][(int)player->x / t];
	y1 = all->map[(int)(player->y + (player->side_walk *
	sin(player->rotation + M_PI / 2) * player->walk_speed)) / t]
	[(int)player->x / t];
	x = all->map[(int)player->y / t]
	[(int)(player->x + (player->walk *
	cos(player->rotation) * player->walk_speed)) / (t)];
	x1 = all->map[(int)player->y / t]
	[(int)(player->x + (player->side_walk *
	cos(player->rotation + M_PI / 2) * player->walk_speed)) / t];
	if (y != '1' && y != '2' && y1 != '1' && y1 != '2')
		y_move(player);
	if (x != '1' && x != '2' && x1 != '1' && x1 != '2')
		x_move(player);
}
