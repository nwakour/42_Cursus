/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:48:38 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/19 17:39:40 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_collision(t_all *all, float x, float y)
{
	int		i;
	int		j;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return (1);
	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (all->map[j][i] != '0')
		return (1);
	else
		return (0);
}
