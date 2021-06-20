/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:40:36 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/15 15:49:57 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int g_nb = 2147483647;
int g_timo = 0;

static int is_sorted(short *a, short *done, t_index *index)
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
	// if (nnb <= g_nb)
	// {
	// 	g_nb = nnb;
	printf("{");
	for (int i = 0; done[i] != 0; ++i)
		printf("%d,", done[i]);
	printf("}\n");
		// print_t_ilists(a, b);
	// 	printf("%d\n", g_nb);
	// }
	// free_all(&a, &b, done);
	return (1);
}

static short shortest_out(short len_a, short len_b, short a, short b)
{
	if (a > len_a / 2 && b <= len_b / 2)
		return (b + (len_a - a));
	else if (a <= len_a / 2 && b > len_b / 2)
		return (a + (len_b - b));
	else if (a <= len_a / 2 && b <= len_b / 2)
		return (a + b - 1);
	else
		return ((len_a - a) + (len_b - b)) + 1;
}

static short shortest_path(short len, short curr, short next)
{
	short path1;
	short path2;

	path1 = next - curr;
	if (path1 < 0)
		path1 *= -1; 
	path2 = shortest_out(len, len, curr + 1, next + 1);
	if (path1 < path2)
		return (path1);
	else
		return (path2);
}

static short my_spot(short len_a, short len_b, short b, short pos, short same)
{
	if (pos <= len_a && same)
		return (shortest_path(len_a, b, pos));
	else if (pos > len_a && same)
		return (shortest_path(pos + 1, b, pos));
	else if (pos <= len_a && !same)
		return (shortest_out(len_a, len_b, pos, b + 1));
	else
	{
		return (shortest_out(pos, len_b, pos, b + 1));
	}
}

static short corr_value (short value, short len)
{
	short per = 6 * len;
	short ret;

	ret = value - per;
	if (ret < 0)
		ret	*= -1;
	ret = per - ret;
	return ret;
}

static short value(short *a, short *b, t_index *index, short biggest, short smallest)
{
	short value = 0;
	int score[10][5] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};
	int len_a = index->a_end - index->a_start;
	int len_b = index->b_end - index->b_start;
	for (short i = index->a_start; i < index->a_end; ++i)
	{
		score[a[i]][2] = my_spot(len_a, len_b, i - index->a_start, a[i], 1);
		for (short j = index->a_start; j < index->a_end; ++j)
		{
			if (a[j] == (a[i] - 1))
			{
				score[a[i]][1] = shortest_path(len_a, i - index->a_start, j - index->a_start);
				score[a[j]][3] = score[a[i]][1];
			}
			else if (a[j] == a[i] - 2)
			{
				score[a[i]][0] = shortest_path(len_a, i - index->a_start, j - index->a_start);
				score[a[j]][4] = score[a[i]][0];
			}
			else if (a[j] == a[i] + 1)
			{
				score[a[i]][3] = shortest_path(len_a, i - index->a_start, j - index->a_start);
				score[a[j]][1] = score[a[i]][3];
			}
			else if (a[j] == a[i] + 2)
			{
				score[a[i]][4] = shortest_path(len_a, i - index->a_start, j - index->a_start);
				score[a[j]][0] = score[a[i]][4];
			}
			else if (a[i] <= smallest + 1)
			{
				if (a[i] == smallest)
				{
					if (a[j] == biggest)
					{
						score[a[i]][1] =  shortest_path(len_a, i - index->a_start, j - index->a_start);
						score[a[j]][3] = score[a[i]][1];
					}
					else if (a[j] == biggest - 1)
					{
						score[a[i]][0] =  shortest_path(len_a, i - index->a_start, j - index->a_start);
						score[a[j]][4] = score[a[i]][0];
					}
				}
				else if (a[i] == smallest + 1 && a[j] == biggest)
				{
					score[a[i]][0] =  shortest_path(len_a, i - index->a_start, j - index->a_start);
					score[a[j]][4] = score[a[i]][0];
				}
			}
			else if (a[i] >= biggest - 1)
			{
				if (a[i] == biggest)
				{
					if (a[j] == smallest)
					{
						score[a[i]][3] =  shortest_path(len_a, i - index->a_start, j - index->a_start);
						score[a[j]][1] = score[a[i]][3];
					}
					else if (a[j] == smallest + 1)
					{
						score[a[i]][4] =  shortest_path(len_a, i - index->a_start, j - index->a_start);
						score[a[j]][0] = score[a[i]][4];
					}
				}
				else if (a[i] == biggest - 1 && a[j] == smallest)
				{
					score[a[i]][4] =  shortest_path(len_a, i - index->a_start, j - index->a_start);
					score[a[j]][0] = score[a[i]][4];
				}
			}
		}
		for (short j = index->b_start ; j < index->b_end; ++j)
		{
			if (b[j] == a[i] - 1)
			{
				score[a[i]][1] = shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
				score[b[j]][3] = score[a[i]][1];
			}
			else if (b[j] == a[i] - 2)
			{
				score[a[i]][0] = shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
				score[b[j]][4] = score[a[i]][0];
			}
			else if (b[j] == a[i] + 1)
			{
				score[a[i]][3] = shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
				score[b[j]][1] = score[a[i]][3];
			}
			else if (b[j] == a[i] + 2)
			{
				score[a[i]][4] = shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
				score[b[j]][0] = score[a[i]][4];
			}
			else if (a[i] <= smallest + 1)
			{
				if (a[i] == smallest)
				{
					if (b[j] == biggest)
					{
						
						score[a[i]][1] =  shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
						score[b[j]][3] = score[a[i]][1];
					}
					else if (b[j] == biggest - 1)
					{
						score[a[i]][0] =  shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
						score[b[j]][4] = score[a[i]][0];
					}
				}
				else if (a[i] == smallest + 1 && b[j] == biggest)
				{
					score[a[i]][0] =  shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
					score[b[j]][4] = score[a[i]][0];
				}
			}
			else if (a[i] >= biggest - 1)
			{
				if (a[i] == biggest)
				{
					if (b[j] == smallest)
					{
						score[a[i]][3] =  shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
						score[b[j]][1] = score[a[i]][3];
					}
					else if (b[j] == smallest + 1)
					{
						score[a[i]][4] =  shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
						score[b[j]][0] = score[a[i]][4];
					}
				}
				else if (a[i] == biggest - 1 && b[j] == smallest)
				{
					score[a[i]][4] =  shortest_out(len_a, len_b, i - index->a_start + 1, j - index->b_start + 1);
					score[b[j]][0] = score[a[i]][4];
				}
			}
		}
	}
	for (short i = index->b_start; i < index->b_end; ++i)
	{
		score[b[i]][2] = my_spot(len_a, len_b, i - index->b_start, b[i] + 1, 0);
		for (short j = index->b_start + 1; j < index->b_end; ++j)
		{
			if (b[j] == b[i] - 1)
			{
				score[b[i]][1] = shortest_path(len_b, i - index->b_start, j - index->b_start);
				score[b[j]][3] = score[b[i]][1];
			}
			else if (b[j] == b[i] - 2)
			{
				score[b[i]][0] = shortest_path(len_b, i - index->b_start, j - index->b_start);
				score[b[j]][4] = score[b[i]][0];
			}
			else if (b[j] == b[i] + 1)
			{
				score[b[i]][3] = shortest_path(len_b, i - index->b_start, j - index->b_start);
				score[b[j]][1] = score[b[i]][3];
			}
			else if (b[j] == b[i] + 2)
			{
				score[b[i]][4] = shortest_path(len_b, i - index->b_start, j - index->b_start);
				score[b[j]][0] = score[b[i]][4];
			}
			else if (b[i] <= smallest + 1)
			{
				if (b[i] == smallest)
				{
					if (b[j] == biggest)
					{
						score[b[i]][1] =  shortest_path(len_b, i - index->b_start, j - index->b_start);
						score[b[j]][3] = score[b[i]][1];
					}
					else if (b[j] == biggest - 1)
					{
						score[b[i]][0] =  shortest_path(len_b, i - index->b_start, j - index->b_start);
						score[b[j]][4] = score[b[i]][0];
					}
				}
				else if (b[i] == smallest + 1 && b[j] == biggest)
				{
					score[b[i]][0] =  shortest_path(len_b, i - index->b_start, j - index->b_start);
					score[b[j]][4] = score[b[i]][0];
				}
			}
			else if (b[i] >= biggest - 1)
			{
				if (b[i] == biggest)
				{
					if (b[j] == smallest)
					{
						score[b[i]][3] =  shortest_path(len_b, i - index->b_start, j - index->b_start);
						score[b[j]][1] = score[b[i]][3];
					}
					else if (b[j] == smallest + 1)
					{
						score[b[i]][4] =  shortest_path(len_b, i - index->b_start, j - index->b_start);
						score[b[j]][0] = score[b[i]][4];
					}
				}
				else if (b[i] == biggest - 1 && b[j] == smallest)
				{
					score[b[i]][4] =  shortest_path(len_b, i - index->b_start, j - index->b_start);
					score[b[j]][0] = score[b[i]][4];
				}
			}
		}
	}
	for (short i = 0; i < 10; ++i)
	{
		for (short j = 0; j < 5; ++j)
			value += score[i][j];
	}
	return (corr_value(value, len_a + len_b));
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
	short values = 0;
	if (sorted || nb > 10)
		return (value(a, b ,index , 4, 0));
	id = is_poss(opper, last, index->a_end - index->a_start, index->b_end - index->b_start) + 1;
	if (id > 0)
	{
		random = ((rand() % (id)));
		corr_ai_op(a, b, opper[random], index);
		last = opper[random];
		nb++;
		done[++add] = opper[random];
		// opper[random] = opper[--id];
		// opper[id] = 0;
		values = inter(a, b, is_sorted(a, done, index), done, nb, last, add, index);
		undo(a, b, last, index);
		// done[add--] = 0;
		// nb--;
		// g_timo++;
	}
	return (values);
}

// static short inter(short *a, short *b, short sorted, short *done, short nb, short last, short add, t_index *index)
// {
// 	short random;
// 	short id;
// 	short opper[11];

// 	if (sorted || nb > 10)
// 		return (1);
// 	id = is_poss(opper, last, index->a_end - index->a_start, index->b_end - index->b_start) + 1;
// 	while(id > 0)
// 	{
// 		random = ((rand() % (id)));
// 		corr_ai_op(a, b, opper[random], index);
// 		last = opper[random];
// 		nb++;
// 		done[++add] = opper[random];
// 		opper[random] = opper[--id];
// 		opper[id] = 0;
// 		inter(a, b, is_sorted(a, done, nb, index), done, nb, last, add, index);
// 		undo(a, b, last, index);
// 		done[add--] = 0;
// 		nb--;
// 		g_timo++;
// 	}
// 	return (1);
// }

short ai(short *a, short *b, t_index *index)
{
	short *done;
	// double time_spent = 0.0;
	// clock_t begin = clock();
	srand(time(NULL));
	done = (short *)malloc(sizeof(short) * 11);
	for (short i = 0; i < 11; ++i)
		done[i] = 0;
	// clock_t end = clock();
	// time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	// fprintf(stderr,"%d operations in %f seconds\n", g_timo, time_spent);
	// printf("%d\n",g_timo);
	return (inter(a, b, 0, done, 0, 0, -1, index));
}
