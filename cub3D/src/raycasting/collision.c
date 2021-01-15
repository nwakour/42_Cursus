/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:47 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/12 15:46:59 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			collision(t_all *all, double y, double x)
{
	int		map_x;
	int		map_y;

	map_x = floor(x / (double)all->info.tile_size);
	map_y = floor(y / (double)all->info.tile_size);
	if (map_x >= 0 && map_x < all->info.cols_nb && map_y >= 0
		&& map_y < all->info.rows_nb)
		return (all->map[map_y][map_x] == '1');
	return (0);
}
