/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_and_floor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:22 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/29 15:19:49 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor(t_all *all)
{
	int i;
	int j;

	i = -1;
	while (++i < (all->info.window_height / 2))
	{
		j = -1;
		while (++j < all->info.window_width)
		{
			all->mlx.img_data[(i + all->info.window_height / 2) *
			all->info.window_width + j] = all->info.color_floor;
		}
	}
}

void	draw_ceiling(t_all *all)
{
	int i;
	int j;

	i = -1;
	while (++i < (all->info.window_height / 2))
	{
		j = -1;
		while (++j < all->info.window_width)
		{
			all->mlx.img_data[i *
			all->info.window_width + j] = all->info.color_ceil;
		}
	}
}
