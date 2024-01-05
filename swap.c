/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:48:42 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/01/03 14:23:17 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *stack, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

int	sa(t_stacks *stacks, int print)
{
	swap(stacks->a, stacks->asize);
	if (print)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stacks *stacks, int print)
{
	swap(stacks->b, stacks->bsize);
	if (print)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stacks *stacks, int print)
{
	swap(stacks->a, stacks->asize);
	swap(stacks->b, stacks->bsize);
	if (print)
		write(1, "ss\n", 3);
	return (1);
}
