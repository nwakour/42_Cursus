/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:03:49 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 17:03:50 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfpwidth(char *hex, t_flags *fl)
{
	size_t len;

	len = strlen(hex);
	if (len < (size_t)fl->wwf)
	{
		fl->wwf -= len + 1;
		while (fl->wwf > 1)
		{
			ft_putchar(' ');
			fl->wwf--;
		}
		hex[0] == '0' && fl->pf != 0 ? ft_putchar(' ') : 0;
		ft_putstrnb("0x", fl);
		if (hex[0] == '0' && fl->pf != 0)
			return ;
		else
			ft_putstrnb(hex, fl);
	}
	else if (ft_putstrnb("0x", fl))
	{
		if (hex[0] == '0' && fl->pf != 0)
			return ;
		else
			ft_putstrnb(hex, fl);
	}
}

void	ft_printfpmwidth(char *hex, t_flags *fl)
{
	size_t len;

	len = strlen(hex);
	if (len < (size_t)fl->wwf)
	{
		fl->wwf -= len + 1;
		ft_putstrnb("0x", fl);
		if (hex[0] == '0' && fl->pf != 0)
			ft_putchar(' ');
		else
			ft_putstrnb(hex, fl);
		while (fl->wwf > 1)
		{
			ft_putchar(' ');
			fl->wwf--;
		}
	}
	else
	{
		ft_putstrnb("0x", fl);
		if (hex[0] == '0' && fl->pf != 0)
			return ;
		else
			ft_putstrnb(hex, fl);
	}
}

void	ft_printfp2(t_flags *fl, char *hex)
{
	if ((fl->wf != 0 || fl->pf != 0) && fl->mf == 0)
		ft_printfpwidth(hex, fl);
	else if ((fl->wf != 0 || fl->pf != 0) && fl->mf == 1)
		ft_printfpmwidth(hex, fl);
	else if (hex[0] == '0' && fl->pf != 0 && fl->wf == 0)
		ft_putstrnb("0x", fl);
	else if (fl->nf == 1 || (hex[0] == '0' && fl->pf == 0) || fl->mf != 0)
	{
		ft_putstrnb("0x", fl);
		ft_putstrnb(hex, fl);
	}
}

void	ft_printfp(va_list args, t_flags *fl)
{
	size_t	p;
	char	*hex;

	if (fl->vf != 0)
		fl->wwf = va_arg(args, int);
	p = va_arg(args, size_t);
	if (fl->wwf < 0)
	{
		fl->wwf *= -1;
		fl->mf = 1;
	}
	if (fl->wpf != 0 || fl->zf != 0)
		return ;
	hex = ft_hexaconv(p, 'x');
	ft_strrev(hex);
	if (p == 0)
		hex = ft_strdup("0");
	ft_printfp2(fl, hex);
	free(hex);
}
