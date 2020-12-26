/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:04 by nwakour           #+#    #+#             */
/*   Updated: 2020/11/28 20:16:46 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_tex(t_all *all)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_NB)
	{
		all->tex[i].tex_p = mlx_xpm_file_to_image(all->mlx.mlx_p,
		all->tex[i].path, &all->tex[i].width, &all->tex[i].height);
		if (!all->tex[i].tex_p)
		{
			perror("Error\nFailed creation texture image\n");
			exit(free_all(all, ERROR));
		}
		all->tex[i].img_data = (int *)mlx_get_data_addr(
								all->tex[i].tex_p, &all->tex[i].bits,
								&all->tex[i].size, &all->tex[i].endian);
		if (!all->tex[i].img_data)
		{
			perror("Error\nFailed creation texture image data\n");
			exit(free_all(all, ERROR));
		}
	}
	if (!(all->tex[S].buffer = malloc(sizeof(float) * all->info.window_width)))
	{
		perror("Error\nAllocation failed\n");
		exit(free_all(all, ERROR));
	}
	ft_bzero(all->tex[S].buffer, sizeof(float) * all->info.window_width);
}