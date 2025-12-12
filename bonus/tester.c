/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:06:33 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/21 15:52:42 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_ordenate(int *args, int size);

void	tester(t_stack *stacks)
{
	char	*cm;
	int		len;

	cm = get_next_line(0);
	while (cm != NULL)
	{
		len = ft_strlen(cm);
		cm[len - 1] = '\0';
		if (!commands_silence(cm, stacks))
		{
			ft_printf("Error");
			return ;
		}
		free(cm);
		cm = get_next_line(0);
	}
	if (is_ordenate(stacks->a, stacks->size_a))
		ft_printf("OK");
	else
		ft_printf("KO");
}

static int	is_ordenate(int *args, int size)
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
