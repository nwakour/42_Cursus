/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:56 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 12:49:45 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static float	get_transformy(t_all *all, t_player *player)
{
	float		spritex;
	float		spritey;
	float		invdet;
	float		transformx;
	float		transformy;

	spritex = all->sprite->x - player->x;
	spritey = all->sprite->y - player->y;
	invdet = 1.0 / (all->sprite->plan_x * all->sprite->dir_y -
	all->sprite->dir_x * all->sprite->plan_y);
	transformx = invdet * (all->sprite->dir_y *
	spritex - all->sprite->dir_x * spritey);
	transformy = invdet * (-all->sprite->plan_y *
	spritex + all->sprite->plan_x * spritey);
	all->sprite->spritescreenx = (int)((all->info.window_width / 2) *
	(1 + -transformx / transformy));
	return (transformy);
}

static void		dist_sprite(t_all *all, t_player *player)
{
	int			i;

	i = 0;
	while (i < all->info.nb_sprite)
	{
		all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
		all->sprite->distance = dist_to_point(player->x,
		player->y, all->sprite->x, all->sprite->y);
		i++;
	}
}

static void		switch_sprite(t_all *all, int i, int j)
{
	float		temp_dist;
	float		temp_y;
	float		temp_x;
	t_sprite	*tmp;

	all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, j);
	tmp = all->sprite;
	temp_dist = all->sprite->distance;
	temp_x = all->sprite->x;
	temp_y = all->sprite->y;
	all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
	tmp->distance = all->sprite->distance;
	tmp->x = all->sprite->x;
	tmp->y = all->sprite->y;
	all->sprite->distance = temp_dist;
	all->sprite->x = temp_x;
	all->sprite->y = temp_y;
}

static	void	sort_sprite(t_all *all)
{
	int			j;
	int			i;
	float		tmp;

	i = -1;
	while (++i < all->info.nb_sprite)
	{
		all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
		tmp = all->sprite->distance;
		j = i + 1;
		while (j < all->info.nb_sprite)
		{
			all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, j);
			if (all->sprite->distance > tmp)
				switch_sprite(all, i, j);
			j++;
		}
	}
}

void			put_sprite(t_all *all, t_player *player)
{
	float		distanceprojection;
	int			i;
	float		transformy;

	i = 0;
	dist_sprite(all, player);
	sort_sprite(all);
	while (i < all->info.nb_sprite)
	{
		all->sprite = (t_sprite*)ft_find_struct_list(all->l_sprite, i);
		distanceprojection = (all->info.window_width / 2)
		/ tan(all->info.fov_angle / 2);
		all->sprite->size = all->info.tile_size * 0.5 / all->sprite->distance *
		distanceprojection;
		if (sprite_visible(all, player) == 1)
		{
			transformy = get_transformy(all, player);
			get_start(all);
			draw_sprite(all, transformy);
		}
		i++;
	}
}