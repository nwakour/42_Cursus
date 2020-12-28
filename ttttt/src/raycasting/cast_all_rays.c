/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:55 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/28 17:09:32 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	void	init_struct_ray(t_ray *ray)
{
	ray->x = 0;
	ray->y = 0;
	ray->x_step = 0;
	ray->y_step = 0;
	ray->hit_x = 0;
	ray->hit_y = 0;
	ray->ver_hit = 0;
	ray->ver_hit_x = 0;
	ray->ver_hit_y = 0;
	ray->hor_hit_y = 0;
	ray->hor_hit_x = 0;
	ray->ver_wall = 0;
	ray->hor_wall = 0;
	ray->ray_down = 0;
	ray->ray_up = 0;
	ray->ray_right = 0;
	ray->ray_left = 0;
	ray->dist = 0;
}

static	void	ray_facing(t_ray *ray)
{
	if (ray->ray_angle > 0 && ray->ray_angle < M_PI)
		ray->ray_down = 1;
	else
		ray->ray_up = 1;
	if (ray->ray_angle < (0.5 * M_PI) || ray->ray_angle > (1.5 * M_PI))
		ray->ray_right = 1;
	else
		ray->ray_left = 1;
}

static	void	shortest_dist_utile(t_ray *ray,
				double vert_hit_distance, double horz_hit_distance)
{
	if (horz_hit_distance < vert_hit_distance)
	{
		ray->hit_x = ray->hor_hit_x;
		ray->hit_y = ray->hor_hit_y;
		ray->dist = horz_hit_distance;
	}
	else
	{
		ray->hit_x = ray->ver_hit_x;
		ray->hit_y = ray->ver_hit_y;
		ray->dist = vert_hit_distance;
	}
	if (vert_hit_distance < horz_hit_distance)
		ray->ver_hit = 1;
}

static void		shortest_dist(t_ray *ray, t_player *player)
{
	double		horz_hit_distance;
	double		vert_hit_distance;

	horz_hit_distance = 0;
	vert_hit_distance = 0;
	if (ray->hor_wall == 1)
		horz_hit_distance = dist_to_point(player->x, player->y,
		ray->hor_hit_x, ray->hor_hit_y);
	else
		horz_hit_distance = MAX_VALUE;
	if (ray->ver_wall == 1)
		vert_hit_distance = dist_to_point(player->x, player->y,
		ray->ver_hit_x, ray->ver_hit_y);
	else
		vert_hit_distance = MAX_VALUE;
	shortest_dist_utile(ray,
	vert_hit_distance, horz_hit_distance);
}

void			cast_all_rays(t_all *all, t_player *player)
{
	int			i;
	double		ray_angle;

	i = -1;
	ray_angle = all->player.rotation - (all->info.fov_angle / 2);
	while (++i < all->info.num_rays)
	{
		all->ray = (t_ray*)ft_find_struct_list(all->l_ray, i);
		if (all->l_ray == NULL || all->ray == NULL)
			ft_struct_list(&all->l_ray, (void**)&all->ray, sizeof(t_ray));
		ray_angle = normalize_angle(ray_angle);
		all->ray->ray_angle = ray_angle;
		init_struct_ray(all->ray);
		ray_facing(all->ray);
		ray_horizontal(all, all->ray, player);
		ray_vertical(all, all->ray, player);
		shortest_dist(all->ray, player);
		ray_angle += (all->info.fov_angle / all->info.num_rays);
		all->ray->ray_angle = ray_angle;
	}
}
