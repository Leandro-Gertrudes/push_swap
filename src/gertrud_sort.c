/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gertrud_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:03:53 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/21 13:51:22 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	starting(t_stack *stacks);
static void	first_part(t_stack *stacks, int *target);
static void	second_part(t_stack *stacks, int *target);

void	g_sort(t_stack *stacks)
{
	int	*target;

	starting(stacks);
	while (stacks->size_a > 3)
	{
		target = get_target(stacks, 1);
		first_part(stacks, target);
		free(target);
	}
	easy_3(stacks);
	while (stacks->size_b > 0)
	{
		target = get_target(stacks, 2);
		second_part(stacks, target);
		free(target);
	}
	target = get_target(stacks, 0);
	while (stacks->a[0] != 0)
	{
		if (target[0] == 1)
			commands("rra", stacks);
		else
			commands("ra", stacks);
	}
	free(target);
}

static void	starting(t_stack *stacks)
{
	int	*rotate;

	if (stacks->size_a < 700)
	{
		rotate = fake_alghorithm(stacks);
		while (stacks->a[0] != rotate[0])
		{
			if (rotate[1] == 1)
				commands("rra", stacks);
			else
				commands("ra", stacks);
		}
		free(rotate);
	}
	commands("pb", stacks);
}

static void	first_part(t_stack *stacks, int *target)
{
	while (target[1] == target[3] && stacks->a[0] != target[0]
		&& stacks->b[0] != target[2])
	{
		if (target[1] == 1)
			commands("rrr", stacks);
		else
			commands("rr", stacks);
	}
	while (stacks->a[0] != target[0])
	{
		if (target[1] == 1)
			commands("rra", stacks);
		else
			commands("ra", stacks);
	}
	while (stacks->b[0] != target[2])
	{
		if (target[3] == 1)
			commands("rrb", stacks);
		else
			commands("rb", stacks);
	}
	commands("pb", stacks);
}

static void	second_part(t_stack *stacks, int *target)
{
	while (target[1] == target[3] && stacks->b[0] != target[0]
		&& stacks->a[0] != target[2])
	{
		if (target[1] == 1)
			commands("rrr", stacks);
		else
			commands("rr", stacks);
	}
	while (stacks->b[0] != target[0])
	{
		if (target[1] == 1)
			commands("rrb", stacks);
		else
			commands("rb", stacks);
	}
	while (stacks->a[0] != target[2])
	{
		if (target[3] == 1)
			commands("rra", stacks);
		else
			commands("ra", stacks);
	}
	commands("pa", stacks);
}
