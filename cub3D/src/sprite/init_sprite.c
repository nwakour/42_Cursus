/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:58 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/16 17:21:56 by nwakour          ###   ########.fr       */
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
					sprite->x = (j + 0.5f) * info.tile_size;
					sprite->y = (i + 0.5f) * info.tile_size;
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
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '2')
				nb_sprite++;
		}
	}
	return (nb_sprite);
}

void			init_sprite(t_all *all, char **map)
{
	int i;

	i = -1;
	all->info.nb_sprite = count_sprite(map);
	while (++i < all->info.nb_sprite)
	{
		ft_struct_list(&all->l_sprite, (void**)&all->sprite, sizeof(t_sprite));
		init_position_sprite(all->info, all->sprite, map, i);
	}
}
