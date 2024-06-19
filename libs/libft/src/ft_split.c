/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:27:59 by apiloian          #+#    #+#             */
/*   Updated: 2023/03/08 15:47:26 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int	word(int count, int i, char *s, char c)
{
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		else
		{
			while (s[i] == c)
				i++;
		}
	}
	return (count);
}

void	free_split(char **split, int index)
{
	while (--index)
		free(split[index]);
	free(split);
}

char	**count_fill(int index, int i, char *s, char c)
{
	int		start;
	char	**split;

	split = malloc((word(0, 0, s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			split[index] = ft_substr(s, start, i - start);
			if (!split[index])
			{
				free_split(split, index);
				return (0);
			}
			index++;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = count_fill(0, 0, (char *)s, c);
	if (!split)
		return (0);
	split[word(0, 0, (char *)s, c)] = 0;
	return (split);
}
