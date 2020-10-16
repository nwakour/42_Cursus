/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfpurs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:49:27 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:49:29 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_writebothpurs2(t_flags *fl, char *z, char *f)
{
	if (fl->mf == 0)
	{
		ft_putstr(f, fl, 0);
		ft_putstr(z, fl, 0);
		ft_putchar('%');
	}
	else if (fl->mf != 0)
	{
		ft_putstr(z, fl, 0);
		ft_putchar('%');
		ft_putstr(f, fl, 0);
	}
}

void	ft_writebothpurs(t_flags *fl)
{
	char	*f;
	char	*z;
	int		i;

	i = 0;
	if (ft_alloc_char(&f, fl->wwf) == NULL)
		return ;
	if (ft_alloc_char(&z, fl->wwwf) == NULL)
		return ;
	while (i < fl->wwf)
		f[i++] = ' ';
	f[i] = '\0';
	i = 0;
	while (i < fl->wwwf)
		z[i++] = '0';
	z[i] = '\0';
	ft_writebothpurs2(fl, z, f);
	ft_free_return(&f, &z, NULL, 0);
}

void	ft_printfpursboth(t_flags *fl)
{
	int		len;

	len = 1;
	if (len < fl->wwwf)
		fl->wwwf -= len;
	else
		fl->wwwf = 0;
	if (len < fl->wwf)
		fl->wwf -= len + fl->wwwf;
	else
		fl->wwf = 0;
	if (fl->wwf < 0)
		fl->wwf = 0;
	ft_writebothpurs(fl);
}

void	ft_printfpurs(va_list args, t_flags *fl)
{
	if (fl->vf != 0)
		fl->wwf = va_arg(args, unsigned int);
	if (fl->vpf != 0)
		fl->wwwf = va_arg(args, unsigned int);
	if (fl->pf != 0 && fl->wwf == 0 && fl->wwwf == 0)
	{
		ft_putchar('%');
		return ;
	}
	if (fl->wwf < 0)
	{
		fl->wwf *= -1;
		fl->mf = 1;
	}
	ft_printfpurs2(fl);
}
