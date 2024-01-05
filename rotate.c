/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:00:43 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/01/03 14:22:05 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *stack, int size)
{
	int	tmp;
	int	i;

	if (size < 2)
		return ;
	tmp = stack[0];
	i = -1;
	while (++i < size - 1)
		stack[i] = stack[i + 1];
	stack[i] = tmp;
}

int	ra(t_stacks *st, int print)
{
	rotate(st->a, st->asize);
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stacks *st, int print)
{
	rotate(st->b, st->bsize);
	if (print)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stacks *st, int print)
{
	rotate(st->a, st->asize);
	rotate(st->b, st->bsize);
	if (print)
		write(1, "rr\n", 3);
	return (1);
}
