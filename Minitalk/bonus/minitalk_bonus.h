/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:50:35 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/26 16:58:02 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

int		ft_isdigit(int c);
void	send_binary(pid_t pid, int c);
void	send_msg(pid_t pid, char *s);
int		revers_digits(int num);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
#endif
