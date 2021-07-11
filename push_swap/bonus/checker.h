/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:02:58 by nwakour           #+#    #+#             */
/*   Updated: 2021/07/11 20:14:10 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../libft/libft.h"

typedef struct		s_ilist
{
	long			nb;
	struct s_ilist	*next;
}					t_ilist;

t_ilist	*ft_int_lstnew(long nb);
void	ft_int_lstadd_back(t_ilist **alst, t_ilist *l_new);
void	ft_int_lstadd_front(t_ilist **alst, t_ilist *l_new);
int		ft_int_lstsize(t_ilist *lst);
t_ilist	*ft_int_lstdup(t_ilist *list);

void	swap(t_ilist *stack);
void	push(t_ilist **a, t_ilist **b);
void	rotate(t_ilist **stack);
void	rev_rotate(t_ilist **stack);

void    print_t_ilists(t_ilist *a, t_ilist *b);

int		is_sorted(t_ilist *a, t_ilist *b);

t_ilist		*parse(char **argv);
void    corr_op(t_ilist *a, t_ilist *b, char *opp);

#endif
