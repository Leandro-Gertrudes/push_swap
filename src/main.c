/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:59:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/21 18:14:41 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(char **argv, t_stack *stack)
{
	int	i;

	if (!argv[0] || !ft_strcmp(argv[0], "free"))
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	if (stack)
	{
		free(stack->a);
		free(stack->b);
		free(stack);
	}
}

static int	set_index(t_stack *stack, int size)
{
	int	*temp;
	int	i;
	int	j;

	i = 0;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return (0);
	while (i < size)
	{
		temp[i] = stack->a[i];
		i++;
	}
	ft_sort_int_tab(temp, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (stack->a[i] != temp[j])
			j++;
		stack->a[i] = j;
		i++;
	}
	free(temp);
	return (1);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_and_set(int argc, char **argv, t_stack *stack)
{
	long	val;
	int		k;
	int		j;

	j = argc - 1;
	while (j >= 1)
	{
		val = ft_atol(argv[j]);
		if (!is_valid_number(argv[j]) || val > 2147483647 || val < -2147483648)
			return (0);
		k = j - 1;
		while (k >= 1)
		{
			if (ft_atol(argv[j]) == ft_atol(argv[k]))
				return (0);
			k--;
		}
		stack->a[j - 1] = (int)val;
		j--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	if (argc == 2)
		argv = ft_split_av(argv[1], ' ', &argc);
	stack = ft_allocation_stacks(argc);
	if (!stack || !argv)
	{
		ft_free(argv, stack);
		return (0);
	}
	if (!check_and_set(argc, argv, stack))
	{
		ft_free(argv, stack);
		ft_printf("Error\n");
		return (0);
	}
	if (!set_index(stack, argc - 1))
	{
		ft_free(argv, stack);
		return (0);
	}
	algorithm(stack);
	ft_free(argv, stack);
}
