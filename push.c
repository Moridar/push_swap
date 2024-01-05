/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:53:17 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/01/03 20:20:35 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(int **to, int **from, int *tosize, int *fromsize)
{
	if (!fromsize)
		return ;
	revrot(*to, ++(*tosize));
	**to = **from;
	rotate(*from, (*fromsize)--);
}

int	pa(t_stacks *st, int print)
{
	push(&st->a, &st->b, &st->asize, &st->bsize);
	if (print)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stacks *st, int print)
{
	push(&st->b, &st->a, &st->bsize, &st->asize);
	if (print)
		write(1, "pb\n", 3);
	return (1);
}
