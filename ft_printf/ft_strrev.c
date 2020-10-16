/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 09:43:58 by nwakour           #+#    #+#             */
/*   Updated: 2019/04/28 15:28:13 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	swp;

	i = ft_strlen(str) - 1;
	j = 0;
	while (j < i)
	{
		swp = str[j];
		str[j] = str[i];
		str[i] = swp;
		i--;
		j++;
	}
}
