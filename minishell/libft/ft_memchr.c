/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 00:24:47 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/14 00:48:39 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*stra;
	unsigned char	a;
	size_t			i;

	stra = (unsigned char *)str;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (stra[i] == a)
		{
			return (&stra[i]);
		}
		i++;
	}
	return (0);
}
