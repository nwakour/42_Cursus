/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:24:00 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/31 16:13:46 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_tex(t_all *all, t_sprite *sprite, int x, int y)
{
	int	textureoffsetx;
	int	distancefromtop;
	int	textureoffsety;
	int	color;
	int	a;

	a = sizeof(all->tex[S].img_data);
	textureoffsetx = (int)(256 * (x - (-all->sprite->size / 2 +
	sprite->spritescreenx)) * all->tex[S].width / all->sprite->size) / 256;
	distancefromtop = (y) * 256 - all->info.window_height
	* 128 + all->sprite->size * 128;
	textureoffsety = ((distancefromtop * all->tex[S].height)
	/ all->sprite->size) / 256;
	if (((textureoffsety * all->tex[S].width) + textureoffsetx) < a)
		return ;
	color = all->tex[S].img_data[(textureoffsety * all->tex[S].width)
	+ textureoffsetx];
	if (color != 0x0)
		all->mlx.img_data[y * all->info.window_width + x] = color;
}

void	draw_sprite(t_all *all, double transformy)
{
	int	y;
	int	x;

	x = all->sprite->start_x;
	while (x < all->sprite->end_x)
	{
		if (transformy > 0 && x > 0 && x < all->info.window_width &&
		transformy < all->tex[S].buffer[x])
		{
			y = all->sprite->start_y;
			while (y < all->sprite->end_y)
			{
				put_tex(all, all->sprite, x, y);
				y++;
			}
		}
		x++;
	}
}

void	get_start(t_all *all)
{
	int	spriteheight;
	int	spritewidth;

	spritewidth = all->sprite->size;
	all->sprite->start_x = -spritewidth / 2 + all->sprite->spritescreenx;
	if (all->sprite->start_x < 0)
		all->sprite->start_x = 0;
	all->sprite->end_x = spritewidth / 2 + all->sprite->spritescreenx;
	if (all->sprite->end_x >= all->info.window_width)
		all->sprite->end_x = all->info.window_width - 1;
	spriteheight = all->sprite->size;
	all->sprite->start_y = -spriteheight / 2 + all->info.window_height / 2;
	if (all->sprite->start_y < 0)
		all->sprite->start_y = 0;
	all->sprite->end_y = spriteheight / 2 + all->info.window_height / 2;
	if (all->sprite->end_y >= all->info.window_height)
		all->sprite->end_y = all->info.window_height - 1;
}

double	cal_angle(t_player *player, double x, double y)
{
	double	vectx;
	double	vecty;
	double	playertospriteangle;
	double	spriteangle;
	double	playerangle;

	vectx = x - player->x;
	vecty = y - player->y;
	playertospriteangle = atan2(vecty, vectx);
	playerangle = normalize_angle(player->rotation);
	spriteangle = playerangle - playertospriteangle;
	if (spriteangle < -M_PI)
		spriteangle += 2.0 * M_PI;
	if (spriteangle > M_PI)
		spriteangle -= 2.0 * M_PI;
	spriteangle = fabs(spriteangle);
	return (spriteangle);
}

int		sprite_visible(t_all *all, t_player *player)
{
	double	spriteangle;
	double	spriteangle_end;
	double	wallspriteangle;
	double	fovsprite;

	spriteangle = fabs(cal_angle(player, all->sprite->x,
		all->sprite->y));
	spriteangle_end = fabs(cal_angle(player, (all->sprite->x
		+ all->sprite->size), (all->sprite->y + all->sprite->size)));
	wallspriteangle = fabs(spriteangle_end - spriteangle);
	fovsprite = all->info.fov_angle / 2 + wallspriteangle;
	if (spriteangle < fovsprite)
		return (1);
	return (0);
}
