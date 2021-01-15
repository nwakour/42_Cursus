/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:56 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/12 15:50:24 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		dist_sprite(t_all *all, t_player *player)
{
	int			i;

	i = -1;
	while (++i < all->info.nb_sprite)
	{
		all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
		all->sprite->dist = dist_to_point(player->x,
		player->y, all->sprite->x, all->sprite->y);
	}
}

static void		switch_sprite(t_all *all, int i, int j)
{
	double		tmp_dist;
	double		tmp_y;
	double		tmp_x;
	t_sprite	*tmp;

	all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, j);
	tmp = all->sprite;
	tmp_dist = all->sprite->dist;
	tmp_x = all->sprite->x;
	tmp_y = all->sprite->y;
	all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
	tmp->dist = all->sprite->dist;
	tmp->x = all->sprite->x;
	tmp->y = all->sprite->y;
	all->sprite->dist = tmp_dist;
	all->sprite->x = tmp_x;
	all->sprite->y = tmp_y;
}

static	void	sort_sprite(t_all *all)
{
	int			j;
	int			i;
	double		tmp;

	i = -1;
	while (++i < all->info.nb_sprite)
	{
		all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
		tmp = all->sprite->dist;
		j = i + 1;
		while (j < all->info.nb_sprite)
		{
			all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, j);
			if (all->sprite->dist > tmp)
				switch_sprite(all, i, j);
			j++;
		}
	}
}

static void		draw_sprite(t_all *all, double y_off,
				double x_off, double size)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	while (++i < size - 1)
	{
		if (x_off + i <= 0 || x_off + i > all->info.window_width - 1)
			continue ;
		all->ray = (t_ray*)ft_find_struct_list(all->l_ray, (int)x_off + i);
		if (all->ray->dist <= all->sprite->dist)
			continue ;
		j = -1;
		while (++j < size - 1)
		{
			if (y_off + j <= 0 || y_off + j > all->info.window_height - 1)
				continue ;
			c = all->tex[S].img_data[(int)((all->tex[S].width) *
			(all->tex[S].width * j / (int)size)
			+ (all->tex[S].width * i / (int)size))];
			if (c != all->tex[S].img_data[0])
				all->mlx.img_data[(int)((j + y_off) *
				all->info.window_width + (i + x_off))] = c;
		}
	}
}

void			put_sprite(t_all *all, t_player *player)
{
	double	angle;
	int		i;
	double	y_off;
	double	x_off;

	dist_sprite(all, player);
	sort_sprite(all);
	i = -1;
	while (++i < all->info.nb_sprite)
	{
		all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
		angle = atan2f(all->sprite->y - all->player.y,
		all->sprite->x - all->player.x);
		while (angle - player->rotation > M_PI)
			angle -= 2 * M_PI;
		while (angle - player->rotation < -M_PI)
			angle += 2 * M_PI;
		all->sprite->size = (all->info.window_width / all->sprite->dist)
		* all->info.tile_size;
		y_off = all->info.window_height / 2 - (int)all->sprite->size / 2;
		x_off = (((180 / M_PI * angle) - (180 / M_PI * all->player.rotation))
		* all->info.window_width) / (double)all->tex[S].width +
		((all->info.window_width / 2.0f) - (int)all->sprite->size / 2.0f);
		draw_sprite(all, y_off, x_off, all->sprite->size);
	}
}
