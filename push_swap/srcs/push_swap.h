/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:09:16 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/15 13:29:49 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_ilist
{
	int				nb;
	struct s_ilist	*next;
}				t_ilist;

t_ilist	*ft_int_lstnew(int nb);
void	ft_int_lstadd_back(t_ilist **alst, t_ilist *l_new);
void	ft_int_lstadd_front(t_ilist **alst, t_ilist *l_new);
int		ft_int_lstsize(t_ilist *lst);
void	ft_int_lstclear(t_ilist **lst);
t_ilist	*ft_int_lstdup(t_ilist *list);
void	swap(t_ilist *stack, char c, int fd);
void	push(t_ilist **a, t_ilist **b, char c, int fd);
void	rotate(t_ilist **stack, char c, int fd);
void	rev_rotate(t_ilist **stack, char c, int fd);
void	pre_sort(t_ilist *stack);
void	index_stack(t_ilist *stack, t_ilist *dupli);
void	sort_stack(t_ilist **a, t_ilist **b);
int		is_sorted(t_ilist *a, t_ilist *b);
void	orgin_stack(t_ilist *a, t_ilist *dup);
int		parse(char **argv, t_ilist	**a);
int		find_smallest_or_biggest(t_ilist *stack, int flag);

#endif
