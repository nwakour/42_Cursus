/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:21:12 by nwakour           #+#    #+#             */
/*   Updated: 2020/12/24 17:39:12 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**array_char(int line, int column)
{
	char	**array;
	int		i;
	int 	j;

	i = -1;
	if (!(array = malloc(sizeof(char*) * (line + 1))))
		return (0);
	while (++i < line)
	{
		if (!(array[i] = malloc(sizeof(char) * (column + 1))))
		{
			while (++i <= 0)
			{
				free(array[i]);
				array[i] = 0;
			}
			return (0);
		}
		j = -1;
		while (++j < column)
			array[i][j] = ' ';
		array[i][column] = '\0';
	}
	array[line] = 0;
	return (array);
}
