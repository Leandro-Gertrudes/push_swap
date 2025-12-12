/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:29:16 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/21 15:44:03 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

typedef struct s_utils
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_utils;

char	**ft_split_av(char const *str, char sep, int *argc);
int		ft_intchr(int *stack, int n, int target, int end);
t_stack	*ft_allocation_stacks(int argc);
//algorithm
int		*fake_alghorithm(t_stack *stacks);
void	easy_combinations(t_stack *stack, int len);
void	g_sort(t_stack *stack);
void	algorithm(t_stack *stack);
void	easy_3(t_stack *stack);
//fake algorithm
void	fake_alghorithm_pt1(t_stack *clone, int *commands);
void	fake_alghorithm_pt2(t_stack *clone, int *commands);
//target utils
int		*get_target(t_stack *stacks, int swap);
void	*zero(t_stack *stacks, int *target);
void	calculate(t_utils *utils, int *commands, int k, int indexmin);
void	simulate(t_utils *utils, int k, int *indexmin);
void	reverse(t_stack *stacks, t_utils **utils, int swap);
//commands
void	commands(char *cm, t_stack *stack);
void	cm_r(char *cm, t_stack *stacks);
void	cm_rr(char *cm, t_stack *stacks);
void	cm_s(char *cm, t_stack *stacks);
void	cm_p(char *cm, t_stack *stack);
//bonus
void	tester(t_stack *stack);
int		commands_silence(char *cm, t_stack *stacks);

#endif
