/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:09:16 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/21 16:06:16 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <math.h>
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

typedef struct		s_index
{
	int	a_start;
	int	b_start;
	int	a_end;
	int	b_end;
}					t_index;

typedef struct		s_pivot
{
	int	limits[3];
	int	off_set[3];
}					t_pivot;

void swap(int *stack, int start);
void push(int *a , int *b, int *a_start, int *b_start);
void rotate(int *stack, int *start, int *end);
void rev_rotate(int *stack, int *start, int *end);
void    print_t_ilists(int *a, int *b, int a_start, int b_start, int a_len, int b_len);
void corr_op(int *a, int *b, t_index *index, char *opp);
void sort_stack(int *a, int *b, t_index *index, t_pivot *pivot);
void get_pivot(int *stack, int start, int end, int len, t_pivot *pivot);

#endif