/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:08:59 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/14 18:20:59 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
	{
		size = 1;
		count = 1;
	}
	if ((str = malloc(size * count)) == 0)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
