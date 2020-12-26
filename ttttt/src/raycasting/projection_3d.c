/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:52 by nwakour           #+#    #+#             */
/*   Updated: 2020/11/30 16:17:20 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	choice_of_texture(t_ray *ray)
{
	if (ray->ray_up && !ray->ver_hit)
		return (0);
	if (ray->ray_down && !ray->ver_hit)
		return (1);
	if (ray->ray_left && ray->ver_hit)
		return (2);
	if (ray->ray_right && ray->ver_hit)
		return (3);
	return (0);
}

static void	draw_wall(t_all *all, t_ray *ray, t_wall *wall, int i)
{
	int	texture_offset_x;
	int	texture_offset_y;
	int	texture_color;
	int	distance_from_top;
	int	index;

	index = choice_of_texture(ray);
	if (ray->ver_hit == 1)
		texture_offset_x = (int)(ray->hit_y * all->tex[index].width /
		all->info.tile_size) % all->tex[index].width;
	else
		texture_offset_x = (int)(ray->hit_x * all->tex[index].width /
		all->info.tile_size) % all->tex[index].width;
	while (wall->top < wall->bot)
	{
		distance_from_top = wall->top + (wall->s_height / 2) -
		(all->info.window_height / 2);
		texture_offset_y = distance_from_top * ((float)all->tex[index].height /
		wall->s_height);
		texture_color = all->tex[index].img_data[(all->tex[index].width *
		texture_offset_y) + texture_offset_x];
		all->mlx.img_data[(wall->top * all->info.window_width) +
		i] = texture_color;
		wall->top++;
	}
}

void		projection_3d(t_all *all)
{
	t_wall	wall;
	int		i;

	i = -1;
	while (++i < all->info.num_rays)
	{
		all->ray = (t_ray*)ft_find_struct_list(all->l_ray, i);
		wall.dist = all->ray->dist * cos(all->ray->ray_angle -
		all->player.rotation);
		all->tex[S].buffer[i] = wall.dist;
		wall.dist_plane = (all->info.window_width / 2) /
		tan(all->info.fov_angle / 2);
		wall.s_height = (all->info.tile_size / wall.dist) *
		wall.dist_plane;
		wall.top = (all->info.window_height / 2) - (wall.s_height / 2);
		if (wall.top < 0)
			wall.top = 0;
		wall.bot = (all->info.window_height / 2) + (wall.s_height / 2);
		if (wall.bot > all->info.window_height)
			wall.bot = all->info.window_height;
		draw_wall(all, all->ray, &wall, i);
	}
}
