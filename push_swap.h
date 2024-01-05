/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:55:39 by bsyvasal          #+#    #+#             */
/*   Updated: 2024/01/05 15:53:24 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	asize;
	int	bsize;
}	t_stacks;

int		turk_sort(t_stacks *st, int print);
int		simple_sort(t_stacks *st, int print);
int		calccount(int acount, int bcount);
int		is_ordered(int arr[], int size);
int		sa(t_stacks *st, int print);
int		sb(t_stacks *st, int print);
int		ss(t_stacks *st, int print);
int		pa(t_stacks *st, int print);
int		pb(t_stacks *st, int print);
int		ra(t_stacks *st, int print);
int		rb(t_stacks *st, int print);
int		rr(t_stacks *st, int print);
int		rra(t_stacks *st, int print);
int		rrb(t_stacks *st, int print);
int		rrr(t_stacks *st, int print);
void	revrot(int *a, int size);
void	rotate(int *a, int size);

#endif
