/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:48 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/28 17:35:01 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	next_vert_intercept(t_all *all, t_ray *ray, double next_vert_y,
								double next_vert_x)
{
	double	tmp;

	while (next_vert_x >= 0 && next_vert_x <= (all->info.cols_nb *
	all->info.tile_size) && next_vert_y >= 0 && next_vert_y <=
	(all->info.rows_nb * all->info.tile_size))
	{
		tmp = 0;
		if (ray->ray_left)
			tmp = 1;
		if (collision(all, next_vert_y, next_vert_x - tmp))
		{
			ray->ver_wall = 1;
			ray->ver_hit_x = next_vert_x;
			ray->ver_hit_y = next_vert_y;
			return ;
		}
		next_vert_x += ray->x_step;
		next_vert_y += ray->y_step;
	}
}

void		ray_vertical(t_all *all, t_ray *ray, t_player *player)
{
	double	next_vert_x;
	double	next_vert_y;

	ray->x = floor(player->x / all->info.tile_size) * all->info.tile_size
	+ (all->info.tile_size * ray->ray_right);
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
	next_vert_x = ray->x;
	next_vert_y = ray->y;
	next_vert_intercept(all, ray, next_vert_y, next_vert_x);
}
