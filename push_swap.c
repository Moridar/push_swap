/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsyvasal <bsyvasal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:55:15 by bsyvasal          #+#    #+#             */
/*   Updated: 2023/12/14 14:55:15 by bsyvasal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	freeandreturn(int ret, int *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	return (ret);
}

static int	*addtostack(char **list, int *i)
{
	int	*stack;

	*i = validateandcount(list);
	if (!*i)
		return (NULL);
	stack = ft_calloc(sizeof(int), *i);
	if (!stack)
		return (NULL);
	*i = -1;
	while (list[++*i])
	{
		stack[*i] = ft_atoi(list[*i]);
		if ((stack[*i] < 0 && list[*i][0] != '-')
			|| (stack[*i] > 0 && list[*i][0] == '-'))
		{
			free(stack);
			return (NULL);
		}
	}
	return (stack);
}

static int	checkdup(t_stacks *stacks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stacks->asize - 1)
	{
		j = i + 1;
		while (j < stacks->asize)
		{
			if (stacks->a[i] == stacks->a[j++])
				return (0);
		}
	}
	return (1);
}

static int	initialize(int argc, char *argv[], t_stacks *stacks)
{
	char	**tmp;

	if (!*argv[1])
		return (write(2, "Error\n", 6));
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			return (0);
		stacks->a = addtostack(tmp, &stacks->asize);
		freestringarray(tmp);
	}
	else
		stacks->a = addtostack(argv + 1, &stacks->asize);
	if (!stacks->a)
		return (write(2, "Error\n", 6));
	if (checkdup(stacks) == 0)
		return (freeandreturn(0, stacks->a));
	stacks->b = ft_calloc(sizeof(int), stacks->asize);
	if (!stacks->b)
		return (freeandreturn(0, stacks->a));
	stacks->bsize = 0;
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc < 2)
		return (1);
	if (initialize(argc, argv, &stacks) != -1)
		return (2);
	if (is_ordered(stacks.a, stacks.asize) != -1)
		simple_sort(&stacks, 1);
	else
		turk_sort(&stacks, 1);
	free(stacks.a);
	free(stacks.b);
	return (0);
}
