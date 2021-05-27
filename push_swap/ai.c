/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:40:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/05/25 17:54:13 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int g_nb = 2147483647;
int g_timo = 0;

static int is_sorted(short *a, short *done, short nnb, t_index *index)
{
	short nb;
	int j;
	// print_t_ilists(a, b);
	if ((index->b_end - index->b_start)|| !(index->a_end - index->a_start))
		return (0);
	j = index->a_start;
	nb = a[j];
	while (++j < index->a_end)
	{
		if (nb > a[j])
			return (0);
		else
			nb = a[j];
	}
	// if (nnb < g_nb)
	// 	g_nb = nnb;
	// (void)done;
	if (nnb <= g_nb)
	{
		g_nb = nnb;
		printf("{");
		for (int i = 0; done[i] != 0; ++i)
			printf("%d,", done[i]);
		printf("}\n");
		// print_t_ilists(a, b);
		printf("%d   %d\n", g_timo ,g_nb);
	}
	// free_all(&a, &b, done);
	return (1);
}

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

static void corr_ai_op(short *a, short *b, short opper, t_index *index)
{

	if (opper == SA)
		swap(a, index->a_start);
	else if (opper == SB)
		swap(b, index->b_start);
	else if (opper == SS)
	{
		swap(a, index->a_start);
		swap(b, index->b_start);
	}
	else if (opper == PA)
		push(a, b, &index->a_start, &index->b_start);
	else if (opper == PB)
		push(b, a, &index->b_start, &index->a_start);
	else if (opper == RA)
		rotate(a, &index->a_start, &index->a_end);
	else if (opper == RB)
		rotate(b, &index->b_start, &index->b_end);
	else if (opper == RR)
	{
		rotate(a, &index->a_start, &index->a_end);
		rotate(b, &index->b_start, &index->b_end);
	}
	else if (opper == RRA)
		rev_rotate(a, &index->a_start, &index->a_end);
	else if (opper == RRB)
		rev_rotate(b, &index->b_start, &index->b_end);
	else if (opper == RRR)
	{
		rev_rotate(a, &index->a_start, &index->a_end);
		rev_rotate(b, &index->b_start, &index->b_end);
	}
}
static void undo(short *a, short *b, short last, t_index *index)
{
	if (last == SA)
		swap(a, index->a_start);
	else if (last == SB)
		swap(b, index->b_start);
	else if (last == SS)
	{
		swap(a, index->a_start);
		swap(b, index->b_start);
	}
	else if (last == PA)
		push(b, a, &index->b_start, &index->a_start);
	else if (last == PB)
		push(a, b, &index->a_start, &index->b_start);
	else if (last == RA)
		rev_rotate(a, &index->a_start, &index->a_end);
	else if (last == RB)
		rev_rotate(b, &index->b_start, &index->b_end);
	else if (last == RR)
	{
		rev_rotate(a, &index->a_start, &index->a_end);
		rev_rotate(b, &index->b_start, &index->b_end);
	}
	else if (last == RRA)
		rotate(a, &index->a_start, &index->a_end);
	else if (last == RRB)
		rotate(b, &index->b_start, &index->b_end);
	else if (last == RRR)
	{
		rotate(a, &index->a_start, &index->a_end);
		rotate(b, &index->b_start, &index->b_end);
	}
}

static short inter(short *a, short *b, short sorted, short *done, short nb, short last, short add, t_index *index)
{
	short random;
	short id;
	short opper[11];

	if (sorted || nb > 10)
		return (1);
	id = is_poss(opper, last, index->a_end - index->a_start, index->b_end - index->b_start) + 1;
	while(id > 0)
	{
		random = ((rand() % (id)));
		corr_ai_op(a, b, opper[random], index);
		last = opper[random];
		nb++;
		done[++add] = opper[random];
		opper[random] = opper[--id];
		opper[id] = 0;
		inter(a, b, is_sorted(a, done, nb, index), done, nb, last, add, index);
		undo(a, b, last, index);
		done[add--] = 0;
		nb--;
		g_timo++;
	}
	return (1);
}

short ai(short *a, short *b, t_index *index)
{
	short *done;
	double time_spent = 0.0;
	clock_t begin = clock();
	srand(time(NULL));
	done = (short *)malloc(sizeof(short) * 11);
	for (short i = 0; i < 11; ++i)
		done[i] = 0;
	inter(a, b, 0, done, 0, 0, -1, index);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(stderr,"%d operations in %f seconds\n", g_timo,time_spent);
	// printf("%d\n",g_timo);
	return (g_nb);
}