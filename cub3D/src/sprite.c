/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:23:23 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/18 14:35:32 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_sprite(t_all *all, int x, int y)
{
	int			i;
	t_sprite	*sprite;

	i = -1;
	all->info.num_sprite++;
	if (!(sprite = malloc(sizeof(*sprite))))
		return ;
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
	sprite->texture = TEX_S;
	if (all->sprite)
		sprite->next = all->sprite;
	else
		sprite->next = NULL;
	all->sprite = sprite;
}

static void	sort_sprite(t_sprite **begin)
{
	t_sprite	*sp;
	t_sprite	*bef;
	t_sprite	*nxt;

	if (*begin)
	{
		sp = *begin;
		bef = 0;
		while (sp->next)
		{
			nxt = sp->next;
			if (sp->dist < nxt->dist)
			{
				sp->next = nxt->next;
				nxt->next = sp;
				if (bef)
					bef->next = nxt;
				else
					*begin = nxt;
				sp = *begin;
			}
			bef = sp;
			sp = sp->next;
		}
	}
}

static void	render_sprite_2(t_all *all, int spt_size, int x_ofst, int y_ofst)
{
	int color;
	int i;
	int j;

	i = -1;
	while (++i < spt_size)
	{
		if (x_ofst + i < 0 || x_ofst + i > WINDOW_HEIGHT)
			continue ;
		if (all->ray[x_ofst + i].dist <= all->sprite->dist)
			continue ;
		j = -1;
		while (++j < spt_size)
		{
			if (y_ofst + j < 0 || y_ofst + j >= WINDOW_HEIGHT)
				continue ;
			color = 0x555555;
			if (color != 0)
				all->mlx.img_data[(y_ofst + j) * WINDOW_WIDTH +
				(WINDOW_WIDTH + x_ofst + i)] = color;
		}
	}
}

static void	render_sprite(t_all *all, t_sprite *sprite, t_player *player)
{
	int		spt_size;
	int		x_ofst;
	int		y_ofst;
	float	sprite_dir;

	sprite_dir = atan2(sprite->y - (player->y / TILE_SIZE),
				sprite->x - (player->x / TILE_SIZE));
	while (sprite_dir - player->rotation > PI)
		sprite_dir -= 2 * PI;
	while (sprite_dir - player->rotation < PI)
		sprite_dir += 2 * PI;
	if (WINDOW_HEIGHT > WINDOW_WIDTH)
		spt_size = WINDOW_HEIGHT / sprite->dist;
	else
		spt_size = WINDOW_WIDTH / sprite->dist;
	x_ofst = (sprite_dir - player->rotation) * WINDOW_WIDTH / FOV_ANGLE +
	(WINDOW_WIDTH / 2 - spt_size / 2);
	y_ofst = WINDOW_HEIGHT / 2 - spt_size / 2;
	render_sprite_2(all, spt_size, x_ofst, y_ofst);
}

void		generete_sprite(t_all *all)
{
	t_sprite *beg;

	beg = all->sprite;
	while (beg)
	{
		beg->dist = dist_points(20, 20, beg->x, beg->y);
		beg = beg->next;
	}
	sort_sprite(&all->sprite);
	beg = all->sprite;
//	while (all->sprite)
//	{
//		render_sprite(all, all->sprite, player);
//		all->sprite = all->sprite->next;
//	}
//	all->sprite = beg;
}
void	render_all_sprites(t_all *all)
{
	t_sprite *beg;

	beg = all->sprite;
		while (all->sprite)
	{
		render_sprite(all, all->sprite, &all->player);
		all->sprite = all->sprite->next;
	}
	all->sprite = beg;
}