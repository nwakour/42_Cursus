/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:23:23 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/20 12:59:28 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vecteur_north(t_sprite *sprite)
{
	sprite->dirx = 0;
	sprite->diry = -1;
	sprite->planx = -0.6;
	sprite->plany = 0;
}

int		count_sprite(char **map)
{
	int	i;
	int	j;
	int	nb_sprite;

	i = -1;
	nb_sprite = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				nb_sprite++;
			}
			j++;
		}
	}
	return (nb_sprite);
}

void	ft_mallocsprite(t_sprite *sprite)
{
	if (!(sprite->x = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		return ;
	}
	if (!(sprite->y = malloc(sizeof(float) * sprite->nb_sprite)))
	{
		return ;
	}
	if (!(sprite->distance = (float *)malloc(sizeof(float) *
	sprite->nb_sprite)))
	{
		return ;
	}
	if (!(sprite->buffer = malloc(sizeof(float) * WINDOW_WIDTH)))
	{
		return ;
	}
	ft_bzero(sprite->buffer, sizeof(float) * WINDOW_WIDTH);
}

static void		load_ptr_and_data_sprite(t_all *all, t_sprite *sprite)
{
	int			bpp;
	int			size_line;
	int			endian;

	sprite->ptr = mlx_xpm_file_to_image(all->mlx.img_data, sprite->path,
	&sprite->width, &sprite->height);
	if (!sprite->ptr)
	{
		return ;
	}
	sprite->data = (int *)mlx_get_data_addr(sprite->ptr,
	&bpp, &size_line, &endian);
	if (!sprite->data)
	{
		return ;
	}
}

static	void	put_to_zero(t_sprite *sprite)
{
	sprite->angle = 0;
	sprite->ptr = 0;
	sprite->data = 0;
	sprite->bpp = 0;
	sprite->endian = 0;
	sprite->size_l = 0;
	sprite->width = 0;
	sprite->height = 0;
}

static void		init_position_sprite(t_sprite *sprite, char **map)
{
	int			i;
	int			j;
	int			id;

	id = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				sprite->x[id] = j * TILE_SIZE + TILE_SIZE / 2;
				sprite->y[id] = i * TILE_SIZE + TILE_SIZE / 2;
				sprite->distance[id] = 0;
				id++;
			}
			j++;
		}
	}
}

static void		init_vecteur(t_sprite *sprite, char player_position)
{
	if (player_position == 'E')
	{
		sprite->dirx = 1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = -0.6;
	}
	else if (player_position == 'S')
	{
		sprite->dirx = 0;
		sprite->diry = 1;
		sprite->planx = 0.6;
		sprite->plany = 0;
	}
	else if (player_position == 'W')
	{
		sprite->dirx = -1;
		sprite->diry = 0;
		sprite->planx = 0;
		sprite->plany = 0.6;
	}
	else if (player_position == 'N')
		init_vecteur_north(sprite);
}

void			init_sprite(t_all *all, t_sprite *sprite, char **map, char player_position)
{
	//sprite->nb_sprite = count_sprite(map);
	ft_mallocsprite(sprite);
	put_to_zero(sprite);
	load_ptr_and_data_sprite(all, sprite);
	init_position_sprite(sprite, map);
	init_vecteur(sprite, player_position);
}

static float	ft_gettransformy(t_sprite *sprite, t_player *player, int id)
{
	float		spritex;
	float		spritey;
	float		invdet;
	float		transformx;
	float		transformy;

	spritex = sprite->x[id] - player->x;
	spritey = sprite->y[id] - player->y;
	invdet = 1.0 / (sprite->planx * sprite->diry -
	sprite->dirx * sprite->plany);
	transformx = invdet * (sprite->diry * spritex - sprite->dirx * spritey);
	transformy = invdet * (-sprite->plany * spritex + sprite->planx * spritey);
	sprite->spritescreenx = (int)((WINDOW_WIDTH / 2) *
	(1 + -transformx / transformy));
	return (transformy);
}

static void		ft_switch(t_sprite *sprite, int i, int j)
{
	float		temp_dist;
	float		temp_y;
	float		temp_x;

	temp_dist = sprite->distance[j];
	temp_x = sprite->x[j];
	temp_y = sprite->y[j];
	sprite->distance[j] = sprite->distance[i];
	sprite->x[j] = sprite->x[i];
	sprite->y[j] = sprite->y[i];
	sprite->distance[i] = temp_dist;
	sprite->x[i] = temp_x;
	sprite->y[i] = temp_y;
}

static	void	ft_sortsprite(t_sprite *sprite)
{
	int			j;
	int			i;

	i = -1;
	while (i++ < sprite->nb_sprite)
	{
		j = i + 1;
		while (j < sprite->nb_sprite)
		{
			if (sprite->distance[j] > sprite->distance[i])
				ft_switch(sprite, i, j);
			j++;
		}
	}
}

void	ft_puttexture(t_all *all, t_sprite *sprite, int x, int y, float sprite_size)
{
	int	textureoffsetx;
	int	distancefromtop;
	int	textureoffsety;
	int	color;
	int	a;

	a = sizeof(sprite->data);
	textureoffsetx = (int)(256 * (x - (-sprite_size / 2 +
	sprite->spritescreenx)) * sprite->width / sprite_size) / 256;
	distancefromtop = (y) * 256 - WINDOW_HEIGHT * 128 + sprite_size * 128;
	textureoffsety = ((distancefromtop * sprite->height) / sprite_size) / 256;
	if (((textureoffsety * sprite->width) + textureoffsetx) < a)
		return ;
	color = sprite->data[(textureoffsety * sprite->width) + textureoffsetx];
	if (color != 0x000000)
		all->mlx.img_data[y * WINDOW_WIDTH + x] = color;
}

void	ft_drawsprite(t_all *all, t_sprite *sprite, float transformy, float sprite_size)
{
	int	y;
	int	x;

	x = sprite->drawstartx;
	while (x < sprite->drawendx)
	{
		if (transformy > 0 && x > 0 && x < WINDOW_WIDTH &&
		transformy < sprite->buffer[x])
		{
			y = sprite->drawstarty;
			while (y < sprite->drawendy)
			{
				ft_puttexture(all, sprite, x, y, sprite_size);
				y++;
			}
		}
		x++;
	}
}

void	ft_getstart(t_sprite *sprite, float sprite_size, float transformy)
{
	int	spriteheight;
	int	spritewidth;

	spritewidth = sprite_size;
	sprite->drawstartx = -spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = spritewidth / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= WINDOW_WIDTH)
		sprite->drawendx = WINDOW_WIDTH - 1;
	spriteheight = sprite_size;
	sprite->drawstarty = -spriteheight / 2 + WINDOW_HEIGHT / 2;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = spriteheight / 2 + WINDOW_HEIGHT / 2;
	if (sprite->drawendy >= WINDOW_HEIGHT)
		sprite->drawendy = WINDOW_HEIGHT - 1;
	(void)sprite_size;
	(void)transformy;
}

float	ft_calculangle(t_player *player, float x, float y)
{
	float	vectx;
	float	vecty;
	float	playertospriteangle;
	float	spriteangle;
	float	playerangle;

	vectx = x - player->x;
	vecty = y - player->y;
	playertospriteangle = atan2(vecty, vectx);
	playerangle = normalize_angle(player->rotation);
	spriteangle = playerangle - playertospriteangle;
	if (spriteangle < -3.14159)
		spriteangle += 2.0 * 3.14159;
	if (spriteangle > 3.14159)
		spriteangle -= 2.0 * 3.14159;
	spriteangle = fabs(spriteangle);
	return (spriteangle);
}

int		ft_spritevisible(t_sprite *sprite, t_player *player,
		int id, float sprite_size)
{
	float	spriteangle;
	float	spriteangle_end;
	float	wallspriteangle;
	float	fovsprite;

	spriteangle = fabs(ft_calculangle(player, sprite->x[id],
		sprite->y[id]));
	spriteangle_end = fabs(ft_calculangle(player, (sprite->x[id]
		+ sprite_size), (sprite->y[id] + sprite_size)));
	wallspriteangle = fabs(spriteangle_end - spriteangle);
	fovsprite = FOV_ANGLE / 2 + wallspriteangle;
	if (spriteangle < fovsprite)
		return (1);
	return (0);
}

void			ft_spritedistance(t_sprite *sprite, t_player *player)
{
	int			id;

	id = 0;
	while (id < sprite->nb_sprite)
	{
		sprite->distance[id] = dist_points(player->x,
		player->y, sprite->x[id], sprite->y[id]);
		id++;
	}
}

static void		ft_zero(t_sprite *sprite)
{
	sprite->drawstartx = 0;
	sprite->drawendx = 0;
	sprite->drawstarty = 0;
	sprite->drawendy = 0;
	sprite->spritescreenx = 0;
}

void			ft_putsprite(t_all *all, t_sprite *sprite, t_player *player)
{
	float		distanceprojection;
	float		sprite_size;
	int			id;
	float		transformy;

	id = 0;
	ft_spritedistance(sprite, player);
	ft_sortsprite(sprite);
	while (id < sprite->nb_sprite)
	{
		distanceprojection = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		sprite_size = TILE_SIZE * 0.5 / sprite->distance[id] *
		distanceprojection;
		ft_zero(sprite);
		if (ft_spritevisible(sprite, player, id, sprite_size) == 1)
		{
			transformy = ft_gettransformy(sprite, player, id);
			ft_getstart(sprite, sprite_size, transformy);
			ft_drawsprite(all, sprite, transformy, sprite_size);
		}
		id++;
	}
}
