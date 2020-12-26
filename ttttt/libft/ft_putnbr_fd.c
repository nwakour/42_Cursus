/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 08:02:08 by nwakour           #+#    #+#             */
/*   Updated: 2019/10/17 08:15:52 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unb;

	if (n < 0)
	{
		unb = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		unb = n;
	if (unb >= 10)
	{
		ft_putnbr_fd(unb / 10, fd);
		ft_putchar_fd(unb % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd(unb % 10 + '0', fd);
	}
}
