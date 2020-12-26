/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 06:59:35 by nwakour           #+#    #+#             */
/*   Updated: 2020/10/20 16:20:03 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_nblen(long int nb)
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

char				*ft_itoa(int n)
{
	char		*str;
	long long	nb;
	int			i;

	nb = n;
	i = ft_nblen(nb);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = '\0';
	i = i - 1;
	if (nb == 0)
		str[i] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}
