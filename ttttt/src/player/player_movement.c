/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:27 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/28 17:39:45 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		player_orientation_angle(double angle)
{
	angle = normalize_angle(angle);
	if ((angle > M_PI * 0.25) && (angle < 0.75 * M_PI))
		return (1);
	else if ((angle > M_PI * 1.25) && (angle < 1.75 * M_PI))
		return (1);
	return (0);
}

static void		update_pos(t_all *all, t_player *player, double y, double x)
{
	double		olddir_x;
	double		oldplan_x;
	double		vectangle;
	int			i;

	i = -1;
	while (++i < all->info.nb_sprite)
	{
		all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
		olddir_x = all->sprite->dir_x;
		oldplan_x = all->sprite->plan_x;
		vectangle = player->turn * player->turn_speed;
		all->sprite->dir_x = all->sprite->dir_x * cos(vectangle) -
		all->sprite->dir_y * sin(vectangle);
		all->sprite->dir_y = olddir_x * sin(vectangle) +
		all->sprite->dir_y * cos(vectangle);
		all->sprite->plan_x = all->sprite->plan_x * cos(vectangle) -
		all->sprite->plan_y * sin(vectangle);
		all->sprite->plan_y = oldplan_x * sin(vectangle) +
		all->sprite->plan_y * cos(vectangle);
	}
	player_collision(all, y, x);
}

void			player_movement(t_all *all, t_player *player)
{
	double		move_step;
	double		new_player_x;
	double		new_player_y;
	int			player_orientation;

	player_orientation = player_orientation_angle(player->rotation);
	player->rotation += player->turn * player->turn_speed;
	move_step = player->walk * player->walk_speed;
	new_player_x = player->x + cos(player->rotation) * move_step;
	new_player_y = player->y + sin(player->rotation) * move_step;
	if (player->translation == -1 || player->translation == 1)
	{
		player->angle = (M_PI * 0.5) - player->rotation;
		if (player_orientation == 1)
		{
			new_player_x = player->x - cos(player->angle) * move_step;
			new_player_y = player->y + sin(player->angle) * move_step;
		}
		else if (player_orientation == 0)
		{
			new_player_x = player->x + cos(player->angle) * -move_step;
			new_player_y = player->y - sin(player->angle) * -move_step;
		}
	}
	update_pos(all, player, new_player_y, new_player_x);
}
