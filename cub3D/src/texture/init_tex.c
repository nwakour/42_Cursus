/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:23:04 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/11 18:43:29 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_tex(t_all *all)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_NB)
	{
		if (!(all->tex[i].tex_p = mlx_xpm_file_to_image(all->mlx.mlx_p,
		all->tex[i].path, &all->tex[i].width, &all->tex[i].height)))
		{
			ft_putstr_fd("Error\nFailed creation texture image\n", 1);
			exit(free_all(all, ERROR));
		}
		if (!(all->tex[i].img_data = (int*)mlx_get_data_addr(all->tex[i].tex_p,
		&all->tex[i].bits, &all->tex[i].size, &all->tex[i].endian)))
		{
			ft_putstr_fd("Error\nFailed creation texture image data\n", 1);
			exit(free_all(all, ERROR));
		}
	}
}
