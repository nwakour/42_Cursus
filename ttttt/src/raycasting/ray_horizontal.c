/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:45 by nwakour           #+#    #+#             */
/*   Updated: 2020/11/05 13:04:57 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	next_hor_intercept(t_all *all, t_ray *ray, float next_hor_y,
								float next_hor_x)
{
	float	tmp;

	while (next_hor_x >= 0 && next_hor_x <= (all->info.cols_nb *
	all->info.tile_size) && next_hor_y >= 0 && next_hor_y <=
	(all->info.rows_nb * all->info.tile_size))
	{
		tmp = 0;
		if (ray->ray_up)
			tmp = 1;
		if (collision(all, next_hor_y - tmp, next_hor_x))
		{
			ray->hor_hit_y = next_hor_y;
			ray->hor_hit_x = next_hor_x;
			ray->hor_wall = 1;
			return ;
		}
		next_hor_x += ray->x_step;
		next_hor_y += ray->y_step;
	}
}

void		ray_horizontal(t_all *all, t_ray *ray, t_player *player)
{
	ray->y = floor(player->y / all->info.tile_size) * all->info.tile_size;
	if (ray->ray_down)
		ray->y += all->info.tile_size;
	ray->x = player->x + ((ray->y - player->y) /
	tan(ray->ray_angle));
	ray->y_step = all->info.tile_size;
	if (ray->ray_up)
		ray->y_step *= -1;
	ray->x_step = all->info.tile_size / tan(ray->ray_angle);
	if (ray->ray_left && ray->x_step > 0)
		ray->x_step *= -1;
	if (ray->ray_right && ray->x_step < 0)
		ray->x_step *= -1;
	next_hor_intercept(all, ray, ray->y, ray->x);
}
