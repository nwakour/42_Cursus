/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:53:03 by nwakour           #+#    #+#             */
/*   Updated: 2020/11/10 16:50:58 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_atoi(const char *str)
{
	int		i;
	float	sum;
	int		sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == ' '  || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		sum = (sum * 10) + str[i] - '0';
		i++;
	}
	return (sign * sum);
}
