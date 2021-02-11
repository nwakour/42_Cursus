/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:18:21 by nwakour           #+#    #+#             */
/*   Updated: 2021/01/30 19:02:33 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef LIBASM_H
#define LIBASM_H


#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
char    *ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

ssize_t	ft_strlen(char *str);
int ft_atoi_base(char *str, char *base);

#endif