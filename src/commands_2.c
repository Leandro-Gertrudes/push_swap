/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:04:21 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/19 16:36:11 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cm_pa(t_stack *stack);
void	cm_pb(t_stack *stack);

void	cm_p(char *cm, t_stack *stack)
{
	if (!ft_strcmp(cm, "pa"))
		cm_pa(stack);
	if (!ft_strcmp(cm, "pb"))
		cm_pb(stack);
}

void	cm_pa(t_stack *stack)
{
	int	i;

	if (stack->size_b > 0)
	{
		i = stack->size_a;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		stack->size_a++;
		i = 0;
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = 0;
		stack->size_b--;
	}
}

void	cm_pb(t_stack *stack)
{
	int	i;

	if (stack->size_a > 0)
	{
		i = stack->size_b;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		stack->size_b++;
		i = 0;
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = 0;
		stack->size_a--;
	}
}
