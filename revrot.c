/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:03:00 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/01/03 14:19:49 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrot(int *stack, int size)
{
	int	tmp;
	int	i;

	if (size < 2)
		return ;
	tmp = stack[size - 1];
	i = size;
	while (--i > 0)
		stack[i] = stack[i - 1];
	stack[i] = tmp;
}

int	rra(t_stacks *st, int print)
{
	revrot(st->a, st->asize);
	if (print)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stacks *st, int print)
{
	revrot(st->b, st->bsize);
	if (print)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stacks *st, int print)
{
	revrot(st->a, st->asize);
	revrot(st->b, st->bsize);
	if (print)
		write(1, "rrr\n", 4);
	return (1);
}
