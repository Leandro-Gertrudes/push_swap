/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:40:15 by lgertrud          #+#    #+#             */
/*   Updated: 2025/05/13 17:26:06 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free(char **arr)
{
	int	i;

	i = 1;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	count_parts(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] && str[i] != sep)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_part(const char *str, char sep, char **arr)
{
	char	*part;
	int		len;

	len = 0;
	while (str[len] && str[len] != sep)
		len++;
	part = (char *)malloc(sizeof(char) * (len + 1));
	if (!part)
	{
		ft_free(arr);
		return (NULL);
	}
	len = 0;
	while (str[len] && str[len] != sep)
	{
		part[len] = str[len];
		len++;
	}
	part[len] = '\0';
	return (part);
}

char	**ft_split_av(char const *str, char sep, int *ac)
{
	int		i;
	char	**arr;

	i = 0;
	*ac = 1;
	arr = (char **)malloc(sizeof(char *) * (count_parts(str, sep) + 2));
	if (!arr || !str)
		return (NULL);
	arr[0] = get_part("free", sep, arr);
	while (str[i] && arr[0])
	{
		if (str[i] != sep)
		{
			arr[*ac] = get_part(&str[i], sep, arr);
			if (!arr[*ac])
				return (NULL);
			while (str[i] && str[i] != sep)
				i++;
			*ac += 1;
		}
		else
			i++;
	}
	arr[*ac] = NULL;
	return (arr);
}
