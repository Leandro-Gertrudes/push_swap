/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:08:31 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/20 16:12:47 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_target_pt2(t_utils *utils, int *target);

int	*get_target(t_stack *stacks, int swap)
{
	t_utils	*utils;
	int		*target;

	target = ft_calloc(5, sizeof(int));
	if (!target)
		return (0);
	if (!swap)
		return (zero(stacks, target));
	reverse(stacks, &utils, swap);
	get_target_pt2(utils, target);
	free(utils);
	return (target);
}

static void	get_target_pt2(t_utils *utils, int *target)
{
	int	commands;
	int	min_commands;
	int	k;
	int	indexmin;
	int	first;

	first = 0;
	k = -1;
	while (++k < utils->len_a)
	{
		indexmin = 0;
		commands = 0;
		simulate(utils, k, &indexmin);
		calculate(utils, &commands, k, indexmin);
		if (first == 0 || commands < min_commands)
		{
			target[0] = utils->a[k];
			target[1] = (k >= utils->len_a / 2);
			target[2] = utils->b[indexmin];
			target[3] = (indexmin >= utils->len_b / 2);
			min_commands = commands;
			first = 1;
		}
	}
}
