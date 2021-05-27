/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:09:16 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/26 15:04:48 by nwakour          ###   ########.fr       */
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

typedef struct		s_index
{
	short	a_start;
	short	b_start;
	short	a_end;
	short	b_end;
}					t_index;

typedef struct		s_node
{
	int *state;
	struct s_node *parent;
	int parent_action;
	int *children;
	int number_of_visits;
	int result;
	int *untried_action;
} 					t_node;

void	ft_int_lstadd_next(t_ilist **alst, t_ilist *l_new);
void	ft_int_lstadd_prev(t_ilist **alst, t_ilist *l_new);
t_ilist	*ft_int_lstnew(int nb);
void swap(short *stack, short start);
void push(short *a , short *b, short *a_start, short *b_start);
void rotate(short *stack, short *start, short *end);
void rev_rotate(short *stack, short *start, short *end);
void    print_t_ilists(short *a, short *b, short a_start, short b_start, short a_len, short b_len);
short	ai(short *a, short *b, t_index *index);
#endif