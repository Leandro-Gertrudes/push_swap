/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_combinations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:41:51 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/16 13:54:27 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_3(t_stack *stack)
{
	int	*args;

	args = stack->a;
	if (args[0] > args[1] && args[1] > args[2])
	{
		commands("ra", stack);
		commands("sa", stack);
	}
	else if (args[0] > args[1] && args[1] < args[2] && args[0] > args[2])
	{
		commands("ra", stack);
	}
	else if (args[0] > args[1] && args[1] < args[2] && args[0] < args[2])
		commands("sa", stack);
	else if (args[0] < args[1] && args[1] > args[2] && args[0] < args[2])
	{
		commands("sa", stack);
		commands("ra", stack);
	}
	else if (args[0] < args[1] && args[1] > args[2] && args[0] > args[2])
		commands("rra", stack);
}

void	easy_combinations(t_stack *stack, int len)
{
	if (len == 2)
		commands("sa", stack);
	if (len == 3)
		easy_3(stack);
}
