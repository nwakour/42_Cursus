/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:47:50 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/18 12:55:54 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_path(char *str, t_all *all, int t)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] == ' ')
		i++;
	len = i;
	while (str[len] && str[len] != ' ')
		len++;
	all->tex[t].path = ft_substr(str, i, len);
}

void	read_resolution(char *str, t_info *info)
{
	int		i;

	i = 1;
	info->res_width = ft_atoi(&str[i]);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	info->res_height = ft_atoi(&str[i]);
}

int		read_floor_ceiling(char *str)
{
	int		i;
	int		pos;
	int		color;
	int		tmp;

	i = 0;
	pos = 0;
	if ((color = ft_atoi(str)) > 255 || color < 0)
		return (-1);
	while (str[i] && pos != 3)
	{
		if (str[i] == ',' && str[i + 1])
		{
			if ((tmp = ft_atoi(&str[i + 1])) > 255 || tmp < 0)
				return (-1);
			color <<= 8;
			color += tmp;
		}
		i++;
	}
	return (color);
}

void	check_file(t_all *all, char *line)
{
	if (line[0] == 'R')
		read_resolution(line, &all->info);
	else if (line[0] == 'N' && line[1] == 'O')
		read_path(&line[2], all, TEX_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		read_path(&line[2], all, TEX_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		read_path(&line[2], all, TEX_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		read_path(&line[2], all, TEX_EA);
	else if (line[0] == 'S')
		read_path(&line[1], all, TEX_S);
	else if (line[0] == 'F')
		all->info.floor = read_floor_ceiling(&line[1]);
	else if (line[0] == 'C')
		all->info.ceilling = read_floor_ceiling(&line[1]);
}

void	read_file(t_all *all)
{
	int		fd;
	char	*line;
	int		i;
	int		lines;

	line = NULL;
	lines = 0;
	fd = open("map.txt", O_RDONLY);
	if (fd < 0)
		return ;
	else
	{
		while ((i = get_next_line(fd, &line)) > 0 && lines != 8)
		{
			if (i == 1 && line[0] != '\0')
			{
				check_file(all, line);
				lines++;
			}
		}
		all->map = ft_read_map(fd);
	}
}
