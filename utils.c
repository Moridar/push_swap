/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:42:07 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/01/05 15:56:08 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_sort(t_stacks *st, int print)
{
	int	i;
	int	count;

	count = 0;
	i = is_ordered(st->a, st->asize);
	if (i == -1)
		count += sa(st, print);
	if (st->asize - i < i)
		i = 0 - (st->asize - i);
	while (i > 0)
	{
		count += ra(st, print);
		i--;
	}
	while (i++ < 0)
		count += rra(st, print);
	return (count);
}

//Checks if the array is ordered in a circular way
//Returns the index of the min value.
int	is_ordered(int arr[], int size)
{
	int	i;
	int	minindex;

	i = -1;
	minindex = 0;
	while (++i < size)
		if (arr[i] < arr[minindex])
			minindex = i;
	i = 0;
	while (i < size - 1)
	{
		if (i + 1 == minindex || arr[i] < arr[i + 1])
			i++;
		else
			return (-1);
	}
	if (minindex && arr[i] > arr[0])
		return (-1);
	return (minindex);
}

int	calccount(int acount, int bcount)
{
	if (acount > 0 && bcount > acount)
		return (bcount + 1);
	if (bcount > 0 && acount > bcount)
		return (acount + 1);
	if (acount < 0 && acount > bcount)
		return (-1 * bcount + 1);
	if (bcount < 0 && bcount > acount)
		return (-1 * acount + 1);
	return (abs(acount) + abs(bcount) + 1);
}
