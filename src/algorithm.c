/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:40:20 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/21 13:52:02 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ordenate(int *args, int size);

void	algorithm(t_stack *stack)
{
	int	*a;
	int	len;

	a = stack->a;
	len = stack->size_a;
	if (is_ordenate(a, len))
		return ;
	if (len < 4)
		easy_combinations(stack, len);
	else
		g_sort(stack);
}

int	is_ordenate(int *args, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (args[i] > args[i + 1])
			return (0);
		i++;
	}
	return (1);
}
