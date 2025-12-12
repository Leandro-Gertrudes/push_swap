/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_algorithm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:37:43 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/21 16:57:21 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cpy(t_stack *src, t_stack *dest);
static void	clone_start(t_stack *stacks, t_stack *clone, int *commands, int i);
static void	clone_end(t_stack *clone, int *commands);
static void	simulation(t_stack *clone, t_stack *stacks, int *rotate, int i);

int	*fake_alghorithm(t_stack *stacks)
{
	t_stack	*clone;
	int		*rotate;
	int		i;

	i = -1;
	rotate = ft_calloc(2, sizeof(int));
	if (!rotate)
		return (0);
	clone = ft_allocation_stacks(stacks->size_a + 1);
	if (!clone)
		return (0);
	while (++i < 70 && i < stacks->size_a)
	{
		cpy(stacks, clone);
		simulation(clone, stacks, rotate, i);
	}
	free(clone->a);
	free(clone->b);
	free(clone);
	return (rotate);
}

static void	simulation(t_stack *clone, t_stack *stacks, int *rotate, int i)
{
	int			commands;
	static int	min_commands;

	commands = 0;
	clone_start(stacks, clone, &commands, i);
	fake_alghorithm_pt1(clone, &commands);
	fake_alghorithm_pt2(clone, &commands);
	clone_end(clone, &commands);
	if (!min_commands || commands < min_commands)
	{
		min_commands = commands;
		rotate[0] = stacks->a[i];
		rotate[1] = (i >= stacks->size_a / 2);
	}
}

static void	clone_start(t_stack *stacks, t_stack *clone, int *commands, int i)
{
	while (clone->a[0] != stacks->a[i])
	{
		cm_r("ra", clone);
		(*commands)++;
	}
	cm_p("pb", clone);
	(*commands)++;
}

static void	clone_end(t_stack *clone, int *commands)
{
	int	*target;

	target = get_target(clone, 0);
	while (clone->a[0] != 0)
	{
		if (target[0] == 1)
			cm_rr("rra", clone);
		else
			cm_r("ra", clone);
		(*commands)++;
	}
	free(target);
}

static void	cpy(t_stack *src, t_stack *dest)
{
	int	i;

	i = 0;
	dest->size_a = src->size_a;
	dest->size_b = src->size_b;
	while (i < src->size_a)
	{
		dest->a[i] = src->a[i];
		i++;
	}
}
