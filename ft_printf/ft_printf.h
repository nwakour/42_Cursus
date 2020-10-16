/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:48:33 by nwakour           #+#    #+#             */
/*   Updated: 2020/01/26 15:48:38 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

ssize_t			g_len;
typedef struct	s_flags
{
	int			mf;
	int			zf;
	int			pf;
	int			wwwf;
	int			wwf;
	int			wpf;
	int			wf;
	int			vpf;
	int			vf;
	int			i;
	int			nf;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_printf_2(t_flags *flags, int *i,
							const char *format, va_list args);
int				ft_printfs(va_list args, t_flags *fl);
int				ft_printfs2(t_flags *fl, int i, char *s);
int				ft_printfc(va_list args, t_flags *fl);
void			ft_printfd(va_list args, t_flags *fl);
void			ft_printfd2(t_flags *fl, int d, char *s);
void			ft_printfu(va_list args, t_flags *fl);
void			ft_printfu2(t_flags *fl, unsigned int u, char *s);
void			ft_printfx(va_list args, char add, t_flags *fl);
void			ft_printfx2(t_flags *fl, unsigned int u, char *hex);
void			ft_printfp(va_list args, t_flags *fl);
void			ft_printfpurs(va_list args, t_flags *fl);
void			ft_printfpurs2(t_flags *fl);
void			ft_printfsboth(char *s, t_flags *fl);
void			ft_printfdboth(int d, char *s, t_flags *fl);
void			ft_printfuboth(char *s, t_flags *fl);
void			ft_printfxboth(char *s, t_flags *fl);
void			ft_printfpursboth(t_flags *fl);
void			ft_printfswrite(char *s, t_flags *fl);
void			ft_printfdwrite(char *s, t_flags *fl);
void			ft_printfxwrite(char *s, t_flags *fl);
void			ft_structflags(const char *f, t_flags *fl);
void			ft_initflag(t_flags *fl);
void			ft_printing(int d, t_flags *fl);
char			*ft_alloc_char(char **s, int i);
char			*ft_hexaconv(size_t n, char x);
void			ft_strrev(char *str);
void			ft_putnbr(long n);
int				ft_nblen(long long nb);
void			ft_putchar(char c);
void			ft_putstr(char *s, t_flags *fl, int i);
int				ft_putstrnb(char *s, t_flags *fl);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_itoa(long long n);
int				ft_free_return(char **ptr, char **ptr2, char **ptr3, int i);

#endif
