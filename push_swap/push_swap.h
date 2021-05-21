/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:09:16 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/21 17:58:33 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct		s_ilist
{
	int				nb;
	struct s_ilist	*next;
}					t_ilist;

t_ilist	*ft_int_lstnew(int nb);
void	ft_int_lstadd_back(t_ilist **alst, t_ilist *l_new);
void	ft_int_lstadd_front(t_ilist **alst, t_ilist *l_new);
int		ft_int_lstsize(t_ilist *lst);

void	swap(t_ilist **stack);
void	push(t_ilist **a, t_ilist **b);
void	rotate(t_ilist **stack);
void 	rev_rotate(t_ilist **stack);

void	corr_op(t_ilist **a, t_ilist **b, char *opp);
void    print_t_ilists(t_ilist *A, t_ilist *B);

#endif