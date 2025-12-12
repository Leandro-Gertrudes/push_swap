/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:27:32 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/21 15:52:13 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	commands_silence(char *cm, t_stack *stacks)
{
	if (!ft_strcmp(cm, "sa") || !ft_strcmp(cm, "sb") || !ft_strcmp(cm, "ss"))
		cm_s(cm, stacks);
	else if (!ft_strcmp(cm, "pa") || !ft_strcmp(cm, "pb"))
		cm_p(cm, stacks);
	else if (!ft_strcmp(cm, "ra") || !ft_strcmp(cm, "rb"))
		cm_r(cm, stacks);
	else if (!ft_strcmp(cm, "rra") || !ft_strcmp(cm, "rrb"))
		cm_rr(cm, stacks);
	else if (!ft_strcmp(cm, "rr"))
	{
		cm_r("ra", stacks);
		cm_r("rb", stacks);
	}
	else if (!ft_strcmp(cm, "rrr"))
	{
		cm_rr("rra", stacks);
		cm_rr("rrb", stacks);
	}
	else
		return (0);
	return (1);
}

void	cm_r(char *cm, t_stack *stacks)
{
	int	*stack;
	int	temp;
	int	i;
	int	len;

	stack = stacks->a;
	len = stacks->size_a;
	if (!ft_strcmp(cm, "rb"))
	{
		stack = stacks->b;
		len = stacks->size_b;
	}
	i = 0;
	if (len <= 1)
		return ;
	len--;
	temp = stack[0];
	while (i < len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}

void	cm_rr(char *cm, t_stack *stacks)
{
	int	*stack;
	int	temp;
	int	len;

	stack = stacks->a;
	len = stacks->size_a;
	if (!ft_strcmp(cm, "rrb"))
	{
		stack = stacks->b;
		len = stacks->size_b;
	}
	if (len <= 1)
		return ;
	len--;
	temp = stack[len];
	while (len > 0)
	{
		stack[len] = stack[len - 1];
		len--;
	}
	stack[len] = temp;
}

void	cm_s(char *cm, t_stack *stacks)
{
	if (!ft_strcmp(cm, "sa"))
	{
		if (stacks->size_a > 0)
			ft_swap(&stacks->a[0], &stacks->a[1]);
	}
	if (!ft_strcmp(cm, "sb"))
	{
		if (stacks->size_b > 0)
			ft_swap(&stacks->b[0], &stacks->b[1]);
	}
	if (!ft_strcmp(cm, "ss"))
	{
		cm_s("sa", stacks);
		cm_s("sb", stacks);
	}
}
