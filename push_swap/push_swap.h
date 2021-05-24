/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:09:16 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/24 21:21:02 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <time.h>

#define SA 1
#define SB 2
#define SS 3
#define PA 4
#define PB 5
#define RA 6
#define RB 7
#define RR 8
#define RRA 9
#define RRB 10
#define RRR 11

typedef struct		s_ilist
{
	struct s_ilist	*prev;
	short			nb;
	struct s_ilist	*next;
}					t_ilist;

t_ilist	*ft_int_lstnew(int nb);
// void	ft_int_lstadd_back(t_ilist **alst, t_ilist *l_new);
// void	ft_int_lstadd_front(t_ilist **alst, t_ilist *l_new);
void	ft_int_lstadd_next(t_ilist **alst, t_ilist *l_new);
void	ft_int_lstadd_prev(t_ilist **alst, t_ilist *l_new);

void	swap(t_ilist **stack);
void	push(t_ilist **a, t_ilist **b);
void	rotate(t_ilist **stack);
void 	rev_rotate(t_ilist **stack);

// void	corr_op(t_ilist **a, t_ilist **b, char *opp);
void    print_t_ilists(t_ilist *a, t_ilist *b, int size_a, int size_b);

int		ai(t_ilist *a, t_ilist *b, short a_len);
#endif