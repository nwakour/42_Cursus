/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 06:59:35 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/17 07:42:14 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nblen(long long nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long long n)
{
	char		*str;
	long long	nb;
	int			i;

	nb = n;
	i = ft_nblen(nb);
	if ((str = (char *)malloc((i + 1) * sizeof(char))) == NULL)
	{
		g_len = -1;
		return (NULL);
	}
	str[i--] = '\0';
	if (nb == 0)
		str[i] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
