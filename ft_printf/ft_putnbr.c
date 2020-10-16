/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 08:02:08 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/17 08:15:52 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long n)
{
	long	unb;

	if (n < 0)
	{
		unb = n * -1;
		ft_putchar('-');
	}
	else
		unb = n;
	if (unb >= 10)
	{
		ft_putnbr(unb / 10);
		ft_putchar(unb % 10 + '0');
	}
	else
	{
		ft_putchar(unb % 10 + '0');
	}
}
