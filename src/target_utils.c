/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:32:16 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/20 16:09:18 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simulate_part_2(t_utils *utils, int *indexmin, int *isgreat);

void	reverse(t_stack *stacks, t_utils **utils, int swap)
{
	*utils = ft_calloc(1, sizeof(t_utils));
	if (!utils)
		return ;
	if (swap == 1)
	{
		(*utils)->a = stacks->a;
		(*utils)->b = stacks->b;
		(*utils)->len_a = stacks->size_a;
		(*utils)->len_b = stacks->size_b;
	}
	else if (swap == 2)
	{
		(*utils)->a = stacks->b;
		(*utils)->b = stacks->a;
		(*utils)->len_b = stacks->size_a;
		(*utils)->len_a = stacks->size_b;
	}
}

void	simulate(t_utils *utils, int k, int *indexmin)
{
	int	i;
	int	isgreat;
	int	min;

	min = 0;
	isgreat = 0;
	i = -1;
	while (++i < utils->len_b)
	{
		if (utils->b[i] > utils->a[k])
		{
			isgreat = utils->b[i];
			if (min == 0)
			{
				min = isgreat;
				*indexmin = i;
			}
			if (isgreat < min)
			{
				min = isgreat;
				*indexmin = i;
			}
		}
	}
	simulate_part_2(utils, indexmin, &isgreat);
}

static void	simulate_part_2(t_utils *utils, int *indexmin, int *isgreat)
{
	int	min;
	int	i;

	i = 0;
	if (!*isgreat)
	{
		min = utils->b[0];
		*indexmin = 0;
		while (i < utils->len_b)
		{
			if (utils->b[i] < min)
			{
				min = utils->b[i];
				*indexmin = i;
			}
			i++;
		}
	}
}

void	calculate(t_utils *utils, int *commands, int k, int indexmin)
{
	if (k >= utils->len_a / 2)
		*commands += utils->len_a - k;
	else
		*commands += k;
	if (indexmin >= utils->len_b / 2)
		*commands += utils->len_b - indexmin;
	else
		*commands += indexmin;
	if ((k < utils->len_a / 2 && indexmin < utils->len_b / 2))
	{
		if (k > indexmin)
			*commands -= indexmin;
		else
			*commands -= k;
	}
	if ((k >= utils->len_a / 2 && indexmin >= utils->len_b / 2))
	{
		if (utils->len_a - k > utils->len_b - indexmin)
			*commands -= (utils->len_b - indexmin);
		else
			*commands -= (utils->len_a - k);
	}
}

void	*zero(t_stack *stacks, int *target)
{
	int	j;

	j = 0;
	while (stacks->a[j] != 0)
		j++;
	target[0] = (j >= stacks->size_a / 2);
	return (target);
}
