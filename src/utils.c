/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:00:32 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/20 17:05:18 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_allocation_stacks(int argc)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = malloc(sizeof(int) * (argc - 1));
	stack->b = malloc(sizeof(int) * (argc - 1));
	if (!stack->a || !stack->b)
	{
		free(stack);
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
		return (NULL);
	}
	stack->size_a = argc - 1;
	stack->size_b = 0;
	return (stack);
}

int	ft_intchr(int *stack, int n, int target, int end)
{
	int	start;

	start = 0;
	while (stack[start] != target)
		start++;
	if (end > start)
	{
		while (start <= end)
		{
			if (stack[start] == n)
				return (1);
			start++;
		}
	}
	else
	{
		while (start >= end)
		{
			if (stack[start] == n)
				return (1);
			start--;
		}
	}
	return (0);
}
