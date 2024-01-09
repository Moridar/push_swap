/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:42:07 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/01/09 09:45:22 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stringarray(char **list)
{
	int	i;

	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
}

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
//Returns -1 if not ordered.
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

//Count the needed actions
//If both need a rotate, count once as rr is used.
int	calc_count(int acount, int bcount)
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

int	validate_and_count(char **list)
{
	int	i;
	int	j;

	i = -1;
	while (list[++i])
	{
		j = 0;
		if (list[i][0] == '-' && ft_isdigit(list[i][1]))
			j++;
		while (ft_isdigit(list[i][j]))
			j++;
		if (list[i][j])
			return (0);
	}
	return (i);
}
