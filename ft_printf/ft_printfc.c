/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:48:54 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:48:55 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfcwidth(t_flags *fl, char c)
{
	while (fl->wwf > 1)
	{
		ft_putchar(' ');
		fl->wwf--;
	}
	ft_putchar(c);
}

void	ft_printfcmwidth(t_flags *fl, char c)
{
	ft_putchar(c);
	while (fl->wwf > 1)
	{
		ft_putchar(' ');
		fl->wwf--;
	}
}

int		ft_printfc(va_list args, t_flags *fl)
{
	char	c;

	if (fl->vf != 0)
		fl->wwf = va_arg(args, int);
	if (fl->vpf != 0)
		fl->wwf = va_arg(args, int);
	c = va_arg(args, int);
	if (fl->wwf < 0)
	{
		fl->wwf *= -1;
		fl->mf = 1;
	}
	if (fl->zf != 0)
		return (0);
	if (fl->wf != 0 && fl->zf == 0 && fl->mf == 0)
		ft_printfcwidth(fl, c);
	else if (fl->wf != 0 && fl->zf == 0 && fl->mf == 1)
		ft_printfcmwidth(fl, c);
	else if (fl->nf == 1 || (fl->mf != 0 && fl->wf == 0) || fl->pf != 0)
		ft_putchar(c);
	return (1);
}
