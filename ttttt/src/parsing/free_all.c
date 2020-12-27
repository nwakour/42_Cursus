/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:22:30 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/27 16:06:19 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			free_map(t_all *all)
{
	int			i;

	i = -1;
	if (all->map)
	{
		while (all->map[++i])
		{
			free(all->map[i]);
			all->map[i] = 0;
		}
		free(all->map);
		all->map = 0;
	}
}

void			free_content(void *content)
{
	if ((char *)content)
	{
		free((char *)content);
		content = 0;
	}
}

static	void	free_texture(t_all *all)
{
	int	i;

	i = -1;
	while (++i < TEXTURE_NB)
	{
		if (all->tex[i].path)
			free(all->tex[i].path);
		if (all->tex[i].tex_p)
			mlx_destroy_image(all->mlx.mlx_p, all->tex[i].tex_p);
		if (all->tex[i].buffer)
			free(all->tex[i].buffer);
		all->tex[i].path = 0;
		all->tex[i].tex_p = 0;
		all->tex[i].buffer = 0;
		all->tex[i].img_data = 0;
	}
}

int				free_all(t_all *all, int ret)
{
	if (all->info.list)
		ft_lstclear(&all->info.list, &free_content);
	if (all->l_sprite)
		ft_lstclear(&all->l_sprite, &free_content);
	if (all->l_ray)
		ft_lstclear(&all->l_ray, &free_content);
	free_map(all);
	free_texture(all);
	if (all->mlx.win_p)
	{
		mlx_clear_window(all->mlx.mlx_p, all->mlx.win_p);
		mlx_destroy_window(all->mlx.mlx_p, all->mlx.win_p);
		if (all->mlx.img_p)
			mlx_destroy_image(all->mlx.mlx_p, all->mlx.img_p);
	}
	all->mlx.win_p = 0;
	all->mlx.img_p = 0;
	all->info.list = 0;
	all->mlx.img_data = 0;
	all->l_ray = 0;
	all->l_sprite = 0;
	all->sprite = 0;
	all->ray = 0;
	return (ret);
}
