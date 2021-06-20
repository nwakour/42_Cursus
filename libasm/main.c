/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:11:03 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/29 16:44:14 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
** FT_STRLEN
*/

// int	main(void)
// {
// 	int		i;

// 	printf("%s : ", "ft_strlen.s");
// 	i = ft_strlen("test++");
// 	printf("%d\n", i);
// 	printf("%s : ", "strlen");
// 	i = strlen("test++");
// 	printf("%d\n", i);
// }

/*
** FT_STRCPY
*/

// int	main(void)
// {
// 	char	str[10] = "nizar";
// 	char	dst[10] = "";
// 	char	*i;

// 	printf("%s : ", "ft_strcpy.s");
// 	i = ft_strcpy(dst, str);
// 	printf("%s\n", i);
// 	printf("%s : ", "strcpy");
// 	i = strcpy(dst, str);
// 	printf("%s\n", i);
// }

/*
** FT_STRCMP
*/

// int		main(void)
// {
// 	int		i;
// 	int		j;
// 	char	*str1 = "btata";
// 	char	*str2 = "msata";

// 	printf("%s : ", "ft_strcmp.s");
// 	i = ft_strcmp(str1, str2);
// 	printf("%d\n", i);
// 	printf("%s : ", "strcmp.s");
// 	j = strcmp(str1, str2);
// 	printf("%d\n", j);
// }

/*
** FT_WRITE
*/

// int		main(void)
// {
// 	ssize_t	i;

// 	printf("%s : \n", "ft_write.s");
// 	i = ft_write(-7, "lol\n", 4);
// 	printf("len is  : %zd\n", i);
// 	printf("sys error is  : %d\n", errno);
// 	printf("sys error is  : %s\n", strerror(errno));
// }

/*
** FT_READ
*/

// int		main(void)
// {
// 	ssize_t	i;
// 	int		j;
// 	char	str[1000000];

// 	printf("%s : \n", "ft_read.s");
// 	j = open("main.c", O_RDONLY);
// 	i = ft_read(j, str, 80);
// 	printf("%s : \n", str);
// 	printf("len is  : %zd\n", i);
// 	printf("sys error is  : %d\n", errno);
// 	printf("sys error is  : %s\n", strerror(errno));
// }

/*
** FT_STRDUP
*/

// int		main(void)
// {
// 	char *str;

// 	printf("%s : \n", "ft_strdup.s");
// 	str = ft_strdup("btata");
// 	printf("sys error is  : %s\n", strerror(errno));
// 	printf("%s \n", str);
// 	printf("len is  : %zd\n", ft_strlen(str));
// }
