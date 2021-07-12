/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 00:49:21 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/12 12:37:28 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char unsigned	*str1a;
	unsigned char	*str2a;
	int				sum;
	size_t			i;

	sum = 0;
	i = 0;
	str1a = (unsigned char *)str1;
	str2a = (unsigned char *)str2;
	while (i < n)
	{
		if (str1a[i] != str2a[i])
		{
			sum = str1a[i] - str2a[i];
			return (sum);
		}
		i++;
	}
	return (0);
}
