/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:48:54 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/20 10:44:18 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_draw(t_draw *draw)
{
	draw->start_x = 0;
	draw->start_y = 0;
	draw->end_x = 0;
	draw->end_y = 0;
	draw->width = 0;
	draw->height = 0;
	draw->color = 0;
}

void	drawline(int *img_data, t_draw draw)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		er2;

	draw.start_x *= MINI_MAP;
	draw.start_y *= MINI_MAP;
	draw.end_x *= MINI_MAP;
	draw.end_y *= MINI_MAP;
	dx = abs(draw.end_x - draw.start_x);
	sx = draw.start_x < draw.end_x ? 1 : -1;
	dy = -abs(draw.end_y - draw.start_y);
	sy = draw.start_y < draw.end_y ? 1 : -1;
	err = dx + dy;
	while ((draw.start_x != draw.end_x) || (draw.start_y != draw.end_y))
	{
		img_data[draw.start_y * WINDOW_WIDTH + draw.start_x] = draw.color;
		er2 = 2 * err;
		if (er2 >= dy)
		{
			err += dy;
			draw.start_x += sx;
		}
		if (er2 <= dx)
		{
			err += dx;
			draw.start_y += sy;
		}
		if (draw.start_x != draw.end_x && draw.start_y != draw.end_y)
			img_data[draw.start_y * WINDOW_WIDTH + draw.start_x] = draw.color;
	}
}

void	drawblock(int *img_data, t_draw draw, int color)
{
	int		end;

	end = draw.start_x + draw.width;
	draw.end_y = draw.start_y + draw.height;
	draw.color = color;
	while (draw.start_x < end)
	{
		draw.end_x = draw.start_x;
		drawline(img_data, draw);
		draw.start_x++;
	}
}
static int	choice_of_texture(t_ray *ray)
{
	if (ray->ray_up && !ray->hit_ver)
		return (0);
	if (ray->ray_down && !ray->hit_ver)
		return (1);
	if (ray->ray_left && ray->hit_ver)
		return (2);
	if (ray->ray_right && ray->hit_ver)
		return (3);
	return (0);
}

void	draw_floor(t_all *all)
{
	int i;
	int j;
	int	color;

	i = 0;
	j = 0;
	color = all->info.floor;
	while (i < (WINDOW_HEIGHT / 2))
	{
		while (j < WINDOW_WIDTH)
		{
			all->mlx.img_data[(i + WINDOW_HEIGHT / 2) *
			WINDOW_WIDTH + (j + 0)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_ceiling(t_all *all)
{
	int i;
	int j;
	int	color;

	i = 0;
	j = 0;
	color = all->info.ceilling;
	while (i < (WINDOW_HEIGHT / 2))
	{
		while (j < WINDOW_WIDTH)
		{
			all->mlx.img_data[(i + 0) * WINDOW_WIDTH + (j + 0)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}

static void	draw_wall(t_all *all, t_ray *ray, t_wall *wall, int i)
{
	int	texture_offset_x;
	int	texture_offset_y;
	int	texture_color;
	int	distance_from_top;
	int	index;

	index = choice_of_texture(ray);
	if (ray->hit_ver == 1)
		texture_offset_x = (int)(ray->hit_y * TILE_SIZE / TILE_SIZE) % TILE_SIZE;
	else
		texture_offset_x = (int)(ray->hit_x * TILE_SIZE /
		TILE_SIZE) % TILE_SIZE;
	while (wall->wall_top < wall->wall_bottom)
	{
		distance_from_top = wall->wall_top + (wall->wall_strip_height / 2) -
		(WINDOW_HEIGHT / 2);
		texture_offset_y = distance_from_top * (TILE_SIZE /
		wall->wall_strip_height);
		texture_color = all->tex[all->ray[i].ray_cord].img_data[(TILE_SIZE *
		texture_offset_y) + texture_offset_x];
		all->mlx.img_data[(wall->wall_top * WINDOW_WIDTH) +
		i] = texture_color;
		wall->wall_top++;
	}
}

void	projection_3d(t_all *all)
{
	int		i;

	i = -1;
	while (++i < NUM_RAYS)
	{
		all->wall.correct_wall_distance = all->ray[i].dist * cos(all->ray[i].ray_angle -
					all->player.rotation);
		all->sprite->buffer[i] = all->wall.correct_wall_distance;
		all->wall.distance_projection_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		all->wall.wall_strip_height = (TILE_SIZE / all->wall.correct_wall_distance) *
		all->wall.distance_projection_plane;
		all->wall.wall_top = (WINDOW_HEIGHT / 2) - (all->wall.wall_strip_height / 2);
		if (all->wall.wall_top < 0)
			all->wall.wall_top = 0;
		all->wall.wall_bottom = (WINDOW_HEIGHT / 2) + (all->wall.wall_strip_height / 2);
		if (all->wall.wall_bottom > WINDOW_HEIGHT)
			all->wall.wall_bottom = WINDOW_HEIGHT;
		draw_wall(all, &all->ray[i], &all->wall, i);
	}
}
