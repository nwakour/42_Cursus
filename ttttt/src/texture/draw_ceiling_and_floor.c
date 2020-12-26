/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_and_floor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:22 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/26 16:53:29 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor(t_all *all)
{
	int i;
	int j;
	int	color;

	i = 0;
	j = 0;
	color = all->info.color_floor;
	while (i < (all->info.window_height / 2))
	{
		while (j < all->info.window_width)
		{
			all->mlx.img_data[(i + all->info.window_height / 2) *
			all->info.window_width + (j + 0)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_ceiling(t_all *all)
{
	int i;
	int j;
	int	color;

	i = 0;
	j = 0;
	color = all->info.color_ceil;
	while (i < (all->info.window_height / 2))
	{
		while (j < all->info.window_width)
		{
			all->mlx.img_data[(i + 0) *
			all->info.window_width + (j + 0)] = color;
			j++;
		}
		j = 0;
		i++;
	}
}
