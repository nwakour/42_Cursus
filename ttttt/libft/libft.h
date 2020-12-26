/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:30:59 by nwakour           #+#    #+#             */
/*   Updated: 2020/11/10 16:31:09 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

float				ft_atoi(const char *str);
void				*ft_bzero(void *ptr, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memccpy(void *str1, void *str2, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *str1, void *str2, size_t n);
void				*ft_memmove(void *str1, void *str2, size_t n);
void				*ft_memset(void *ptr, int x, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isspace (int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strcpy(char *dest, char *src);
char				**array_char(int line, int column);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void*));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));
void				ft_list_remove_one_if(t_list **begin_list, void *data_ref,
								int (*cmp)(), void (*free_fct)(void *));
t_list				*ft_list_find(t_list *begin_list, void *data_ref, size_t n,
					int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *));
int					get_next_line(int fd, char **line);
void				ft_struct_bezero(void *param, size_t size);
void				*ft_find_struct_list(t_list *list, size_t i);
int					ft_struct_list(t_list **list, void **param, size_t size);

#endif
