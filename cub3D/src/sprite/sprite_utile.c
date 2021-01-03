/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:24:00 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/03 14:46:38 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_tex(t_all *all, t_sprite *sprite, int x, int y)
{
	int	x_offset;
	int	dist_top;
	int	y_offset;
	int	color;
	int	a;

	a = sizeof(all->tex[S].img_data);
	x_offset = (int)(256 * (x - (-all->sprite->size / 2 +
	sprite->spritescreenx)) * all->tex[S].width / all->sprite->size) / 256;
	dist_top = (y) * 256 - all->info.window_height
	* 128 + all->sprite->size * 128;
	y_offset = ((dist_top * all->tex[S].height)
	/ all->sprite->size) / 256;
	if (((y_offset * all->tex[S].width) + x_offset) < a)
		return ;
	color = all->tex[S].img_data[(y_offset * all->tex[S].width)
	+ x_offset];
	if (color != 0x0)
		all->mlx.img_data[y * all->info.window_width + x] = color;
}

void	draw_sprite(t_all *all, double transformy)
{
	int	y;
	int	x;

	x = all->sprite->start_x;
	while (x < all->sprite->end_x)
	{
		if (transformy > 0 && x > 0 && x < all->info.window_width &&
		transformy < all->tex[S].buffer[x])
		{
			y = all->sprite->start_y;
			while (y < all->sprite->end_y)
			{
				put_tex(all, all->sprite, x, y);
				y++;
			}
		}
		x++;
	}
}

void	get_start(t_all *all)
{
	int	sprite_height;
	int	sprite_width;

	sprite_width = all->sprite->size;
	all->sprite->start_x = -sprite_width / 2 + all->sprite->spritescreenx;
	if (all->sprite->start_x < 0)
		all->sprite->start_x = 0;
	all->sprite->end_x = sprite_width / 2 + all->sprite->spritescreenx;
	if (all->sprite->end_x >= all->info.window_width)
		all->sprite->end_x = all->info.window_width - 1;
	sprite_height = all->sprite->size;
	all->sprite->start_y = -sprite_height / 2 + all->info.window_height / 2;
	if (all->sprite->start_y < 0)
		all->sprite->start_y = 0;
	all->sprite->end_y = sprite_height / 2 + all->info.window_height / 2;
	if (all->sprite->end_y >= all->info.window_height)
		all->sprite->end_y = all->info.window_height - 1;
}

double	cal_angle(t_player *player, double x, double y)
{
	double	vect_x;
	double	vect_y;
	double	s_to_p_angle;
	double	sprite_angle;
	double	player_rot;

	vect_x = x - player->x;
	vect_y = y - player->y;
	s_to_p_angle = atan2(vect_y, vect_x);
	player_rot = normalize_angle(player->rotation);
	sprite_angle = player_rot - s_to_p_angle;
	if (sprite_angle < -M_PI)
		sprite_angle += 2.0 * M_PI;
	if (sprite_angle > M_PI)
		sprite_angle -= 2.0 * M_PI;
	sprite_angle = fabs(sprite_angle);
	return (sprite_angle);
}

int		sprite_visible(t_all *all, t_player *player)
{
	double	sprite_angle;
	double	sprite_angle_end;
	double	wall_sprite_angle;
	double	sprite_fov;

	sprite_angle = fabs(cal_angle(player, all->sprite->x,
		all->sprite->y));
	sprite_angle_end = fabs(cal_angle(player, (all->sprite->x
		+ all->sprite->size), (all->sprite->y + all->sprite->size)));
	wall_sprite_angle = fabs(sprite_angle_end - sprite_angle);
	sprite_fov = all->info.fov_angle / 2 + wall_sprite_angle;
	if (sprite_angle < sprite_fov)
		return (1);
	return (0);
}
