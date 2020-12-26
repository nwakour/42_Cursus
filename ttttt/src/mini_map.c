/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:12 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 14:35:27 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	draw_map_utile(t_all *all, int y, int x, int color)
{
	int	i;
	int	j;
	int tmp;

	tmp = x;
	i = -1;
	while (++i < all->info.tile_size * MINI_MAP)
	{
		j = -1;
		while (++j < all->info.tile_size * MINI_MAP)
		{
			all->mlx.img_data[y * all->info.window_width + x] = color;
			x++;
		}
		y++;
		x = tmp;
	}
}

static	void	draw_map(t_all *all, char **map)
{
	int			i;
	int			j;
	int			x;
	int			y;

	i = -1;
	while (++i < all->info.rows_nb)
	{
		j = -1;
		while (++j < all->info.cols_nb)
		{
			x = j * all->info.tile_size * MINI_MAP;
			y = i * all->info.tile_size * MINI_MAP;
			if (map[i][j] == '2')
				draw_map_utile(all, y, x, 0xFF0000);
			else if (map[i][j] == '0' || ft_strchr("NSEW", map[i][j]))
				draw_map_utile(all, y, x, 16777215);
		}
	}
}

static void		draw_player(t_all *all, int x, int y, int width)
{
	int		i;
	int		j;

	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < width)
		{
			all->mlx.img_data[(i + y - width / 2) * all->info.window_width +
			(j + x - width / 2)] = 0x0078FF;
		}
	}
}

void			mini_map(t_all *all, t_player *player, char **map)
{
	draw_map(all, map);
	draw_player(all, player->x * MINI_MAP, player->y *
	MINI_MAP, player->radius);
}
