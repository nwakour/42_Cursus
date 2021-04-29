/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:24:19 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/14 00:21:02 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, void *str2, size_t n)
{
	unsigned char	*str1a;
	unsigned char	*str2a;

	str1a = (unsigned char *)str1;
	str2a = (unsigned char *)str2;
	if (str1a < str2a)
	{
		return (ft_memcpy(str1a, str2a, n));
	}
	if (str1a > str2a)
	{
		while (n--)
		{
			str1a[n] = str2a[n];
		}
	}
	return (str1);
}
