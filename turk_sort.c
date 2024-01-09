/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:15:39 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/01/09 09:46:04 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_action(t_stacks *st, int count[2], int to_b, int print)
{
	while (count[0] > 0 && count[1] > 0)
	{
		count[0] -= rr(st, print);
		count[1]--;
	}
	while (count[0] > 0)
		count[0] -= ra(st, print);
	while (count[1] > 0)
		count[1] -= rb(st, print);
	while (count[0] < 0 && count[1] < 0)
	{
		count[0] += rrr(st, print);
		count[1]++;
	}
	while (count[0] < 0)
		count[0] += rra(st, print);
	while (count[1] < 0)
		count[1] += rrb(st, print);
	if (to_b)
		pb(st, print);
	else
		pa(st, print);
	return (1);
}

int	to_b_count_actions(t_stacks *st, int i, int print, int onlycount)
{
	int	count[2];

	count[0] = i;
	if (st->asize - i < i)
		count[0] = 0 - (st->asize - i);
	count[1] = 0;
	if (!(st->a[i] > st->b[count[1]] && st->a[i] < st->b[st->bsize - 1]))
		count[1]++;
	while (count[1] && count[1] < st->bsize
		&& !(st->a[i] > st->b[count[1]] && st->a[i] < st->b[count[1] - 1]))
		count[1]++;
	if (count[1] == st->bsize)
		while (--count[1] > 0 && st->b[count[1]] < st->b[count[1] - 1])
			;
	if (st->bsize - count[1] < count[1])
		count[1] = 0 - (st->bsize - count[1]);
	if (onlycount)
		return (calc_count(count[0], count[1]));
	return (do_action(st, count, 1, print));
}

int	to_a_count_actions(t_stacks *st, int i, int print, int onlycount)
{
	int	count[2];

	count[1] = i;
	if (st->bsize - i < i)
		count[1] = 0 - (st->bsize - i);
	count[0] = 0;
	if (!(st->b[i] < st->a[count[0]] && st->b[i] > st->a[st->asize - 1]))
		count[0]++;
	while (count[0] && count[0] < st->asize
		&& !(st->b[i] < st->a[count[0]] && st->b[i] > st->a[count[0] - 1]))
		count[0]++;
	if (count[0] == st->asize)
		while (--count[0] > 0 && st->a[count[0]] > st->a[count[0] - 1])
			;
	if (st->asize - count[0] < count[0])
		count[0] = 0 - (st->asize - count[0]);
	if (onlycount)
		return (calc_count(count[1], count[0]));
	return (do_action(st, count, 0, print));
}

int	push_all_cheapest(t_stacks *st, int size, int print, int to_b)
{
	int	i;
	int	count;
	int	cheapest;
	int	cheapestindex;

	i = 0;
	cheapest = 1000;
	while (i < size)
	{
		if (to_b)
			count = to_b_count_actions(st, i, 0, 1);
		else
			count = to_a_count_actions(st, i, 0, 1);
		if (count < cheapest)
		{
			cheapest = count;
			cheapestindex = i;
		}
		i++;
	}
	if (to_b)
		to_b_count_actions(st, cheapestindex, print, 0);
	else
		to_a_count_actions(st, cheapestindex, print, 0);
	return (cheapest);
}

int	turk_sort(t_stacks *st, int print)
{
	int	count;

	count = 0;
	if (st->asize > 3)
		count += pb(st, print);
	while (st->asize > 3 && is_ordered(st->a, st->asize) == -1)
		count += push_all_cheapest(st, st->asize, print, 1);
	if (is_ordered(st->a, st->asize) == -1)
		count += sa(st, print);
	while (st->bsize)
		count += push_all_cheapest(st, st->bsize, print, 0);
	count += simple_sort(st, print);
	return (count);
}
