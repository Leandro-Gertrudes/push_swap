/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_algorithm_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:17:42 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/20 16:51:49 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fake_alghorithm_pt1_util(t_stack *clone,
				int *commands, int *target);
static void	fake_alghorithm_pt2_util(t_stack *clone,
				int *commands, int *target);

void	fake_alghorithm_pt1(t_stack *clone, int *commands)
{
	int	*target;

	while (clone->size_a > 3)
	{
		target = get_target(clone, 1);
		while (target[1] == target[3] && clone->a[0] != target[0]
			&& clone->b[0] != target[2])
		{
			if (target[1] == 1)
			{
				cm_rr("rra", clone);
				cm_rr("rrb", clone);
			}
			else
			{
				cm_r("ra", clone);
				cm_r("rb", clone);
			}
			(*commands)++;
		}
		fake_alghorithm_pt1_util(clone, commands, target);
		free(target);
	}
}

static void	fake_alghorithm_pt1_util(t_stack *clone, int *commands, int *target)
{
	while (clone->a[0] != target[0])
	{
		if (target[1] == 1)
			cm_rr("rra", clone);
		else
			cm_r("ra", clone);
		(*commands)++;
	}
	while (clone->b[0] != target[2])
	{
		if (target[3] == 1)
			cm_rr("rrb", clone);
		else
			cm_r("rb", clone);
		(*commands)++;
	}
	cm_p("pb", clone);
	(*commands)++;
}

void	fake_alghorithm_pt2(t_stack *clone, int *commands)
{
	int	*target;

	while (clone->size_b > 0)
	{
		target = get_target(clone, 2);
		while (target[1] == target[3] && clone->b[0] != target[0]
			&& clone->a[0] != target[2])
		{
			if (target[1] == 1)
			{
				cm_rr("rra", clone);
				cm_rr("rrb", clone);
			}
			else
			{
				cm_r("ra", clone);
				cm_r("rb", clone);
			}
			(*commands)++;
		}
		fake_alghorithm_pt2_util(clone, commands, target);
		free(target);
	}
}

static void	fake_alghorithm_pt2_util(t_stack *clone, int *commands, int *target)
{
	while (clone->b[0] != target[0])
	{
		if (target[1] == 1)
			cm_rr("rrb", clone);
		else
			cm_r("rb", clone);
		(*commands)++;
	}
	while (clone->a[0] != target[2])
	{
		if (target[3] == 1)
			cm_rr("rra", clone);
		else
			cm_r("ra", clone);
		(*commands)++;
	}
	cm_p("pa", clone);
	(*commands)++;
}
