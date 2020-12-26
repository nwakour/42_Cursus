/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:59:41 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/19 13:39:10 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ray_coordinate(float ray_angle, int hit_ver, int hit_hoz)
{
	float	an;

	an = rad_to_angle(ray_angle);
	if (((an < 45) || (an >= 45 && an < 90)) && hit_ver)
		return (NO);
	else if (((an < 45) || (an >= 45 && an < 90)) && hit_hoz)
		return (EA);
	else if (((an >= 90 && an < 135) || (an >= 135 && an < 180)) && hit_ver)
		return (SO);
	else if (((an >= 90 && an < 135) || (an >= 135 && an < 180)) && hit_hoz)
		return (EA);
	else if (((an >= 180 && an < 225) || (an >= 225 && an < 270)) && hit_ver)
		return (SO);
	else if (((an >= 180 && an < 225) || (an >= 225 && an < 270)) && hit_hoz)
		return (WE);
	else if (an >= 270 && hit_ver)
		return (NO);
	else if (an >= 270 && hit_hoz)
		return (WE);
	else
		return (-1);
}

void	init_ray(t_ray *ray)
{
	ray->inter_x = 0;
	ray->inter_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit_x = 0;
	ray->hit_y = 0;
	ray->ver_hit_x = 0;
	ray->ver_hit_y = 0;
	ray->hoz_hit_x = 0;
	ray->hoz_hit_y = 0;
	ray->was_hit_vert = 0;
	ray->hit_ver = 0;
	ray->hit_hoz = 0;
	ray->ray_up = 0;
	ray->ray_down = 0;
	ray->ray_left = 0;
	ray->ray_right = 0;
	ray->dist = 0;
}

void	ray_fac(t_ray *ray)
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

void	low_ray(t_ray *ray, t_player *player)
{
	float		hoz_dist;
	float		ver_dist;

	hoz_dist = ray->hit_hoz ? dist_points(player->x, player->y, ray->hoz_hit_x, ray->hoz_hit_y) : INT_MAX;
	ver_dist = ray->hit_ver ? dist_points(player->x, player->y, ray->ver_hit_x, ray->ver_hit_y) : INT_MAX;
	if (ver_dist < hoz_dist)
	{
		ray->dist = ver_dist;
		ray->hit_x = ray->ver_hit_x;
		ray->hit_y = ray->ver_hit_y;
		ray->hit_ver = 1;
		ray->hit_hoz = 0;
	}
	else
	{
		ray->dist = hoz_dist;
		ray->hit_x = ray->hoz_hit_x;
		ray->hit_y = ray->hoz_hit_y;
		ray->hit_ver = 0;
		ray->hit_hoz = 1;
	}
	ray->ray_cord = ray_coordinate(ray->ray_angle, ray->hit_ver, ray->hit_hoz);
}

void	next_ray_hoz(t_all *all, t_ray *ray, float next_hoz_y, float next_hoz_x)
{
	float	i;

	while (next_hoz_x >= 0 && next_hoz_x <= WINDOW_WIDTH && next_hoz_y >= 0 && next_hoz_y <= WINDOW_HEIGHT)
	{
		i = 0;
		if (ray->ray_up)
			i = 1;
		if (ft_collision(all, next_hoz_x, next_hoz_y - i))
		{
			ray->hoz_hit_x = next_hoz_x;
			ray->hoz_hit_y = next_hoz_y;
			ray->hit_hoz = 1;
			break ;
		}
		else
		{
			next_hoz_x += ray->step_x;
			next_hoz_y += ray->step_y;
		}
	}
}

void	ray_hoz(t_all *all, t_ray *ray, t_player *player)
{
	float	next_hoz_y;
	float	next_hoz_x;

	ray->inter_y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	ray->inter_y += ray->ray_down ? TILE_SIZE : 0;
	ray->inter_x = player->x + (ray->inter_y - player->y) / tan(ray->ray_angle);
	ray->step_y = TILE_SIZE;
	ray->step_y *= ray->ray_up ? -1 : 1;
	ray->step_x = TILE_SIZE / tan(ray->ray_angle);
	ray->step_x *= (ray->ray_left && ray->step_x > 0) ? -1 : 1;
	ray->step_x *= (ray->ray_right && ray->step_x < 0) ? -1 : 1;
	next_hoz_x = ray->inter_x;
	next_hoz_y = ray->inter_y;
	next_ray_hoz(all, ray, next_hoz_y, next_hoz_x);
}

void	next_ray_ver(t_all *all, t_ray *ray, float next_ver_y, float next_ver_x)
{
	float	i;

	while (next_ver_x >= 0 && next_ver_x <= WINDOW_WIDTH && next_ver_y >= 0 && next_ver_y <= WINDOW_HEIGHT)
	{
		i = 0;
		if (ray->ray_left)
			i = 1;
		if (ft_collision(all, next_ver_x - i, next_ver_y))
		{
			ray->ver_hit_x = next_ver_x;
			ray->ver_hit_y = next_ver_y;
			ray->hit_ver = 1;
			break ;
		}
		else
		{
			next_ver_x += ray->step_x;
			next_ver_y += ray->step_y;
		}
	}
}

void	ray_ver(t_all *all, t_ray *ray, t_player *player)
{
	float	next_ver_y;
	float	next_ver_x;

	ray->inter_x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	ray->inter_x += ray->ray_right ? TILE_SIZE : 0;
	ray->inter_y = player->y + (ray->inter_x - player->x) * tan(ray->ray_angle);
	ray->step_x = TILE_SIZE;
	ray->step_x *= ray->ray_left ? -1 : 1;
	ray->step_y = TILE_SIZE * tan(ray->ray_angle);
	ray->step_y *= (ray->ray_up && ray->step_y > 0) ? -1 : 1;
	ray->step_y *= (ray->ray_down && ray->step_y < 0) ? -1 : 1;
	next_ver_x = ray->inter_x;
	next_ver_y = ray->inter_y;
	next_ray_ver(all, ray, next_ver_y, next_ver_x);
}

void	cast_all_rays(t_all *all, t_ray *ray)
{
	int		i;
	float dist;

	dist = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	i = 0;
	while (i < NUM_RAYS)
	{
		//all->ray[i].ray_angle = all->player.rotation - (FOV_ANGLE / 2);
		all->ray[i].ray_angle = all->player.rotation + atan((i - (NUM_RAYS / 2)) / dist);
		all->ray[i].ray_angle = normalize_angle(all->ray[i].ray_angle);
		init_ray(&ray[i]);
		ray_fac(&ray[i]);
		ray_hoz(all, &ray[i], &all->player);
		ray_ver(all, &ray[i], &all->player);
		low_ray(&ray[i], &all->player);
		i++;
	}
}

void	render_rays(t_all *all)
{
	int		i;

	i = -1;
	all->draw.start_x = all->player.x;
	all->draw.start_y = all->player.y;
	all->draw.color = 0xFF0000;
	while (++i < NUM_RAYS)
	{
		all->draw.end_x = all->ray[i].hit_x;
		all->draw.end_y = all->ray[i].hit_y;
		drawline(all->mlx.img_data, all->draw);
	}
}
