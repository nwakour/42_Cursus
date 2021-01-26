/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:11:03 by abenouda          #+#    #+#             */
/*   Updated: 2021/01/26 18:40:41 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
int		strlen_test(char *str)
{
	int		ret1;
	int		ret2;

	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	if (ret1 == ret2)
	{
		printf("%d | ", ret1);
		printf("%d\t", ret2);
		printf("[OK]\n");
	}
	else
		printf("KO]\n");
	return (1);
}

int		strcpy_test(char *src)
{
	char	dest1[1000];
	char	dest2[1000];

	bzero(dest1, 1000);
	bzero(dest2, 1000);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("[OK]\n");
	else
		printf("KO]\n");
	return (1);
}

int		strcmp_test(char *s1, char *s2)
{
	int		ret1;
	int		ret2;

	ret1 = strcmp(s1, s2);
	ret2 = ft_strcmp(s1, s2);
	printf("%d | ", ret2);
	printf("%d\t\t", ret1);
	if ((ret1 > 0 && ret2 > 0) || (ret1 < 0 && ret2 < 0)
	|| (ret1 == 0 && ret2 == 0))
		printf("[OK]\n");
	else
		printf("KO]\n");
	return (1);
}

// int		write_test(char *str)
// {
// 	int		ft_write_pipe[2];
// 	char	buf[1000];
// 	int		ret;

// 	bzero(buf, 1000);
// 	if (pipe(ft_write_pipe) < 0)
// 		exit(EXIT_FAILURE);
// 	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
// 	write(ft_write_pipe[1], str, strlen(str));
// 	ret = read(ft_write_pipe[0], buf, 1000);
// 	buf[ret] = '\0';
// 	if (!strcmp(buf, str))
// 		printf("" GREEN "[OK] " RESET "");
// 	else
// 		printf("" RED "[KO] " RESET "");
// 	close(ft_write_pipe[1]);
// 	close(ft_write_pipe[0]);
// 	return (1);
// }

// int		read_test(char *str)
// {
// 	int		ft_read_pipe[2];
// 	char	buf[1000];
// 	int		ret;

// 	bzero(buf, 1000);
// 	if (pipe(ft_read_pipe) < 0)
// 		exit(EXIT_FAILURE);
// 	fcntl(ft_read_pipe[0], F_SETFL, O_NONBLOCK);
// 	write(ft_read_pipe[1], str, strlen(str));
// 	ret = ft_read(ft_read_pipe[0], buf, 1000);
// 	buf[ret] = '\0';
// 	if (!strcmp(buf, str))
// 		printf("" GREEN "[OK] " RESET "");
// 	else
// 		printf("" RED "[KO] " RESET "");
// 	close(ft_read_pipe[1]);
// 	close(ft_read_pipe[0]);
// 	return (1);
// }

int		strdup_test(char *str)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup(str);
	str2 = strdup(str);
	//printf("%s", str2);
	if (!strcmp(str1, str2))
		printf("[OK]\n");
	else
		printf("KO]\n");
	free(str1);
	free(str2);
	return (1);
}

int		main(void)
{
	/*
	** FT_STRLEN
	*/
	printf("ft_strlen.s :\n");
	strlen_test("allo");
	strlen_test("");
	strlen_test("on test tout ce qu'on peut mon gars");
	strlen_test("allo \0 mon gars");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	strlen_test("        ");
	printf("\n\n");

	/*
	** FT_STRCPY
	*/
	printf("%-12s :  ", "ft_strcpy.s\n");
	strcpy_test("abc");
	strcpy_test("");
	strcpy_test("allo mon gars");
	strcpy_test("allo \0 mon gars");
	strcpy_test("ca fou koi allo");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	strcpy_test("        ");
	printf("\n\n");

	// /*
	// ** FT_STRCMP
	// */
	printf("%-12s :  ", "ft_strcmp.s\n");
	strcmp_test("allo", "allo");
	strcmp_test("abcdef", "zcdef");
	strcmp_test("", "wtf");
	strcmp_test("on test tout ce qu'on peut mon gars", "   ");
	strcmp_test("", "");
	strcmp_test("beta", "");
	strcmp_test("te\0", "\0");
	strcmp_test("\xff\xff", "\xff\xff");
	strcmp_test("\xff\x80", "\xff\x00");
	strcmp_test("\xff\xfe", "\xff");
	strcmp_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, ed pulvinar nullam.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n\n");

	// /*
	// ** FT_WRITE
	// */
	// printf("%-12s :  ", "ft_write.s");
	// write_test("");
	// write_test("testjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
	// write_test("test allo");
	// write_test("test allo \0 what");
	// printf("\n\n");

	// /*
	// ** FT_READ
	// */

	// printf("%-12s :  ", "ft_read.s");
	// read_test("allo");
	// read_test("allo mon gars");
	// read_test("allo \0 mon bars");
	// read_test("");
	// read_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	// printf("\n\n");

	// /*
	// ** FT_STRDUP
	// */
	printf("ft_strdup.s\n");
	strdup_test("allo");
	strdup_test("allo wtf");
	strdup_test("");
	strdup_test("allo \0 mon bars");
	strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n");
}
