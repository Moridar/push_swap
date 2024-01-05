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

static int	*addtostack(char **list, int *size)
{
	int	i;
	int	j;
	int	*stack;

	i = -1;
	while (list[++i])
	{
		j = 0;
		if (list[i][j] == '-')
			j++;
		while (ft_isdigit(list[i][j]))
			j++;
		if (list[i][j])
			return (NULL);
	}
	stack = ft_calloc(sizeof(int), i);
	if (!stack)
		return (NULL);
	*size = -1;
	while (list[++*size])
		stack[*size] = ft_atoi(list[*size]);
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
			{
				printf("%d appeared twice\n", stacks->a[i]);
				return (0);
			}
		}
	}
	return (1);
}

static int	freeandreturn(int ret, int *stack)
{
	free(stack);
	printf("ERROR invalid arguments");
	return (ret);
}

static int	initialize(int argc, char *argv[], t_stacks *stacks)
{
	char	**tmp;

	stacks->asize = argc - 1;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			return (0);
		stacks->a = addtostack(tmp, &stacks->asize);
		free(tmp);
	}
	else
		stacks->a = addtostack(argv + 1, &stacks->asize);
	if (!stacks->a)
		return (printf("ERROR invalid arguments\n"));
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
	printf("count: %d\n", turk_sort(&stacks, 1));
	free(stacks.a);
	free(stacks.b);
	return (0);
}
