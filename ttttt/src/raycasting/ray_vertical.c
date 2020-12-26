/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:48 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/22 10:34:44 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	next_vert_intercept(t_all *all, t_ray *ray, float next_vert_touch_y,
								float next_vert_touch_x)
{
	float	tmp;

	while (next_vert_touch_x >= 0 && next_vert_touch_x <= all->info.window_width
	&& next_vert_touch_y >= 0 && next_vert_touch_y <= all->info.window_height)
	{
		tmp = 0;
		if (ray->ray_left)
			tmp = 1;
		if (collision(all, next_vert_touch_y, next_vert_touch_x - tmp))
		{
			ray->ver_wall = 1;
			ray->ver_hit_x = next_vert_touch_x;
			ray->ver_hit_y = next_vert_touch_y;
			return ;
		}
		next_vert_touch_x += ray->x_step;
		next_vert_touch_y += ray->y_step;
	}
}

void		ray_vertical(t_all *all, t_ray *ray, t_player *player)
{
	float	next_vert_touch_x;
	float	next_vert_touch_y;

	ray->x = floor(player->x / all->info.tile_size) * all->info.tile_size;
	if (ray->ray_right)
		ray->x += all->info.tile_size;
	ray->y = player->y + (ray->x - player->x) *
	tan(ray->ray_angle);
	ray->x_step = all->info.tile_size;
	if (ray->ray_left)
		ray->x_step *= -1;
	ray->y_step = all->info.tile_size * tan(ray->ray_angle);
	if (ray->ray_up && ray->y_step > 0)
		ray->y_step *= -1;
	if (ray->ray_down && ray->y_step < 0)
		ray->y_step *= -1;
	next_vert_touch_x = ray->x;
	next_vert_touch_y = ray->y;
	next_vert_intercept(all, ray, next_vert_touch_y, next_vert_touch_x);
}
