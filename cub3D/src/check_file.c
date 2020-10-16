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
	int	i;

	i = 1;
	info->res_width = ft_atoi(&str[i]);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	info->res_height = ft_atoi(&str[i]);
}

int	read_floor_ceiling(char *str)
{
	int i;
	int pos;
	int color;
	int tmp;

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