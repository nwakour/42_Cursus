/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:58 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 14:41:21 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		init_position_sprite(t_info info, t_sprite *sprite,
				char **map, int sprite_nb)
{
	int			i;
	int			j;
	int			id;

	i = -1;
	id = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '2')
			{
				if (id < sprite_nb)
					id++;
				else
				{
					sprite->x = j * info.tile_size + info.tile_size / 2;
					sprite->y = i * info.tile_size + info.tile_size / 2;
					sprite->distance = 0;
					return ;
				}
			}
		}
	}
}

static int		count_sprite(char **map)
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

static void		init_vect(t_sprite *sprite, char player_position)
{
	if (player_position == 'E')
	{
		sprite->dir_x = 1;
		sprite->plan_y = -0.6;
	}
	else if (player_position == 'S')
	{
		sprite->dir_y = 1;
		sprite->plan_x = 0.6;
	}
	else if (player_position == 'W')
	{
		sprite->dir_x = -1;
		sprite->plan_y = 0.6;
	}
	else if (player_position == 'N')
	{
		sprite->dir_y = -1;
		sprite->plan_x = -0.6;
	}
}

void			init_sprite(t_all *all, char **map, char player_position)
{
	int i;

	i = -1;
	all->info.nb_sprite = count_sprite(map);
	while (++i < all->info.nb_sprite)
	{
		ft_struct_list(&all->l_sprite, (void**)&all->sprite, sizeof(t_sprite));
		init_position_sprite(all->info, all->sprite, map, i);
		init_vect(all->sprite, player_position);
	}
}
