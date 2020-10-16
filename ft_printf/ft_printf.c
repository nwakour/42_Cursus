/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:48:15 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:48:17 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initflag(t_flags *fl)
{
	fl->mf = 0;
	fl->zf = 0;
	fl->pf = 0;
	fl->wwwf = 0;
	fl->wpf = 0;
	fl->wwf = 0;
	fl->wf = 0;
	fl->vpf = 0;
	fl->vf = 0;
	fl->i = 0;
	fl->nf = 0;
}

void	ft_printfspecif(char format, va_list args, t_flags *flags)
{
	if (format == 'c')
		ft_printfc(args, flags);
	else if (format == 's')
		ft_printfs(args, flags);
	else if (format == 'd' || format == 'i')
		ft_printfd(args, flags);
	else if (format == 'u')
		ft_printfu(args, flags);
	else if (format == 'x' || format == 'X')
		ft_printfx(args, format, flags);
	else if (format == 'p')
		ft_printfp(args, flags);
	else if (format == '%')
		ft_printfpurs(args, flags);
}

void	ft_printf_2(t_flags *flags, int *i, const char *format, va_list args)
{
	ft_structflags(&format[*i], flags);
	*i += flags->i;
	ft_printfspecif(format[*i], args, flags);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags flags;
	int		i;

	i = 0;
	g_len = 0;
	va_start(args, format);
	while (format[i] != '\0' && g_len != -1)
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
				ft_putchar(format[i]);
			else if (g_len != -1)
			{
				ft_initflag(&flags);
				ft_printf_2(&flags, &i, format, args);
			}
		}
		else if (g_len != -1)
			ft_putchar(format[i]);
		format[i] != '\0' && g_len != -1 ? ++i : 0;
	}
	va_end(args);
	return (g_len);
}
