/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:40:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/24 21:26:12 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int g_nb = 2147483647;
int g_timo = 0;
// static void free_all(t_ilist **a, t_ilist **b, int *done)
// {
// 	t_ilist *next_node;
// 	t_ilist *current;

// 	if (done)
// 		free(done);
// 	done = NULL;
// 	next_node = (*a);
// 	current = (*a);
// 	while (next_node)
// 	{
// 		current = next_node;
// 		next_node = next_node->next;
// 		free(current);
// 	}
// 	next_node = (*b);
// 	current = (*b);
// 	while (next_node)
// 	{
// 		current = next_node;
// 		next_node = next_node->next;
// 		free(current);
// 	}
// }

static int is_sorted(t_ilist *a, t_ilist *b, short *done, short nnb, short a_size)
{
	t_ilist *tmp;
	short nb;
	// print_t_ilists(a, b);
	if (b)
		return (0);
	if (!a)
		return (0);
	tmp = a;
	nb = tmp->nb;
	while (--a_size)
	{
		tmp = tmp->next;
		if (nb > tmp->nb)
			return (0);
		else
			nb = tmp->nb;
		// a_size--;
	}
	// if (nnb < g_nb)
	// 	g_nb = nnb;
	(void)done;
	if (nnb <= g_nb)
	{
		g_nb = nnb;
		printf("{");
		for (int i = 0; done[i] != 0; ++i)
			printf("%d,", done[i]);
		printf("}\n");
		// print_t_ilists(a, b);
		printf("%d\n", g_nb);
	}
	// free_all(&a, &b, done);
	return (1);
}

// static void add_poss(int *opper, int add)
// {
// 	int i;

// 	i = 0;
// 	while (i < 11 && opper[i] != 0)
// 		i++;
// 	opper[i] = add;
// 	if (i < 10)
// 		opper[++i] = 0;
// }

static int is_poss(short *opper, short last, short a_len, short b_len)
{
	short index = -1;

	if (a_len > 1)
	{
		if (last != SA)
			opper[++index] = SA;
		if (last != RRA)
			opper[++index] = RA;
		if (last != RA)
			opper[++index] = RRA;
	}
	if (b_len > 1)
	{
		if (last != SB)
			opper[++index] = SB;
		if (last != RRB)
			opper[++index] = RB;
		if (last != RB)
			opper[++index] = RRB;
	}
	if (b_len > 1 && a_len > 1)
	{
		if (last != SS)
			opper[++index] = SS;
		if (last != RRR)
			opper[++index] = RR;
		if (last != RR)
			opper[++index] = RRR;
	}
	if (b_len > 0 && last != PB)
		opper[++index] = PA;
	if (a_len > 0 && last != PA)
		opper[++index] = PB;
	return index;
}

// static void cp_list(t_ilist *list, t_ilist **cp)
// {
// 	t_ilist *tmp;
// 	tmp = list;

// 	while (tmp)
// 	{
// 		ft_int_lstadd_back(cp, ft_int_lstnew(tmp->nb));
// 		tmp = tmp->next;
// 	}
// }

// static void add_done(int *done, int opper)
// {
// 	int i;
// 	i = 0;
	
// 	while (done[i] != 0)
// 		i++;
// 	done[i] = opper;
// 	done[++i] = 0;
// }

static void corr_ai_op(t_ilist **a, t_ilist **b, short opper, short *a_len, short *b_len)
{

	if (opper == SA)
		swap(a);
	else if (opper == SB)
		swap(b);
	else if (opper == SS)
	{
		swap(a);
		swap(b);
	}
	else if (opper == PA)
	{
		push(a, b);
		(*a_len)++;
		(*b_len)--;
	}
	else if (opper == PB)
	{
		push(b, a);
		(*a_len)--;
		(*b_len)++;
	}
	else if (opper == RA)
		rotate(a);
	else if (opper == RB)
		rotate(b);
	else if (opper == RR)
	{
		rotate(a);
		rotate(b);
	}
	else if (opper == RRA)
		rev_rotate(a);
	else if (opper == RRB)
		rev_rotate(b);
	else if (opper == RRR)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	// (*last) = opper;
	// add_done(done, opper);
}
static void undo(t_ilist **a, t_ilist **b, short last, short *a_len, short *b_len)
{
	if (last == SA)
		swap(a);
	else if (last == SB)
		swap(b);
	else if (last == SS)
	{
		swap(a);
		swap(b);
	}
	else if (last == PA)
	{
		push(b, a);
		(*a_len)--;
		(*b_len)++;
	}
	else if (last == PB)
	{
		push(a, b);
		(*a_len)++;
		(*b_len)--;
	}
	else if (last == RA)
		rev_rotate(a);
	else if (last == RB)
		rev_rotate(b);
	else if (last == RR)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else if (last == RRA)
		rotate(a);
	else if (last == RRB)
		rotate(b);
	else if (last == RRR)
	{
		rotate(a);
		rotate(b);
	}
}

static short inter(t_ilist *a, t_ilist *b, short sorted, short *done, short nb, short last, short add, short a_len, short b_len)
{
	short random;
	short index;
	short opper[11];

	if (sorted || nb > 10)
		return (1);
	index = is_poss(opper, last, a_len, b_len) + 1;
	while(index > 0)
	{
		random = ((rand() % (index)));
		corr_ai_op(&a, &b, opper[random], &a_len, &b_len);
		last = opper[random];
		nb++;
		done[++add] = opper[random];
		opper[random] = opper[--index];
		opper[index] = 0;
		inter(a, b, is_sorted(a, b, done, nb, a_len), done, nb, last, add, a_len, b_len);
		undo(&a, &b, last, &a_len, &b_len);
		done[add--] = 0;
		nb--;
		g_timo++;
	}
	return (1);
}

int ai(t_ilist *a, t_ilist *b, short a_len)
{
	short *done;
	done = (short *)malloc(sizeof(short) * 11);
	// int opper[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	// int *opper = (int *)malloc(sizeof(int) * 11);
	srand(time(NULL));
	for (short i = 0; i < 11; ++i)
		done[i] = 0;
	inter(a, b, 0, done, 0, 0, -1, a_len, 0);
	printf("%d\n",g_timo);
	return (g_nb);
}