/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:12 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 12:31:23 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
}

char	**ft_array_char(int line, int column)
{
	char	**array;
	int		i;
	int		j;

	i = -1;
	array = malloc(sizeof(char *) * (line + 1));
	if (!array)
		return (NULL);
	while (++i < line)
	{
		array[i] = malloc(sizeof(char) * (column + 1));
		if (!array[i])
		{
			free_array(array);
			return (NULL);
		}
		j = -1;
		while (++j < column)
			array[i][j] = ' ';
		array[i][column] = '\0';
	}
	array[line] = 0;
	return (array);
}
