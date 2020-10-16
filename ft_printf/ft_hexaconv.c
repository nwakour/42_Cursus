/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:47:56 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:47:58 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zhexo(size_t n)
{
	char *hexa;

	if (ft_alloc_char(&hexa, 1) == NULL)
		return (NULL);
	hexa[n++] = '0';
	hexa[n] = '\0';
	return (hexa);
}

char	*ft_hexaconv(size_t n, char add)
{
	char	*hexa;
	size_t	i;
	size_t	len;
	size_t	j;

	len = 0;
	i = n;
	if (n == 0)
		return (ft_zhexo(0));
	while (n && ++len)
		n /= 16;
	if (ft_alloc_char(&hexa, len) == NULL)
		return (NULL);
	n = i;
	i = 0;
	while (n)
	{
		j = n % 16;
		hexa[i++] = j < 10 ? j + 48 : j + add - 33;
		n = n / 16;
	}
	hexa[i] = '\0';
	return (hexa);
}
