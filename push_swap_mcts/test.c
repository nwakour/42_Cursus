/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwakour <nwakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:00:26 by nwakour           #+#    #+#             */
/*   Updated: 2021/06/13 18:32:02 by nwakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    print_t_ilists(short *a, short *b, short a_start, short b_start, short a_end, short b_end)
// {
//     printf("\t ____________________________ \n");
//     printf("\t|____ %c _____|\t|____ %c _____|\n",
//         'a', 'b');
//     while (a_start < a_end || b_start < b_end)
//     {
//         if (a_start < a_end && b_start < b_end)
//             printf("\t[%11d ]\t[%11d ]\n", a[a_start++], b[b_start++]);
//         else if (a_start < a_end)
//         {
//             printf("\t[%11d ]\t[%11c ]\n", a[a_start++], ' ');
//         }
//        else if (b_start < b_end)
//         {
//             printf("\t[%11c ]\t[%11d ]\n", ' ', b[b_start++]);
//         }
//     }
//     printf("\t------------------------------\n");
// }


short shortest_out(short len_a, short len_b, short a, short b)
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

short shortest_path(short len, short curr, short next)
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

short my_spot(short len_a, short len_b, short b, short pos, short same)
{
	int path; 

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

short corr_value (short value, short len)
{
	short per = 6 * len;
	short ret;

	ret = value - per;
	if (ret < 0)
		ret	*= -1;
	ret = per - ret;
	return ret;
}

void value(short *a, short *b, t_index *index, short biggest, short smallest)
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
		{
			value += score[i][j];
			printf("%d, ",score[i][j]);
		}
		printf("\n");
	}
	printf("value = %d\n", corr_value(value, len_a + len_b));
}

int main()
{
	t_index index;
	short *a;
	short *b;
	// short size = 5;

	a = (short*)malloc(sizeof(int) * 11);
	b = (short*)malloc(sizeof(int) * 5);

	index.a_start = 0;
	index.a_end = 5;
	index.b_start = 0;
	index.b_end = 5;

	a[0] = 8;
	a[1] = 6;
	a[2] = 4;
	a[3] = 0;
	a[4] = 2;
	
	
	b[0] = 5;
	b[1] = 1;
	b[2] = 3;
	b[3] = 7;
	b[4] = 9;

	value(a, b, &index, 9, 0);
	return (0);
}
