/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:10:44 by apiloian          #+#    #+#             */
/*   Updated: 2023/01/30 16:14:07 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	check(char *s1, char const *set)
{
	while (*set != '\0')
	{
		if (*s1 == *set)
			return (1);
		else
			set++;
	}
	return (0);
}

int	trim_vpered(char *str, char const *set)
{
	int	start;

	start = 0;
	while (check(str, set))
	{
		str++;
		start++;
	}
	return (start);
}

int	trim_nazad(char *str, char const *set, char *f)
{
	int	finish;	

	finish = ft_strlen(str);
	while (*str)
		str++;
	str--;
	while (check(str, set))
	{
		if (str == f)
			break ;
		str--;
		finish--;
	}
	return (finish);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		finish;
	int		len;
	char	*str;

	if (!s1)
		return (0);
	str = (char *)s1;
	if (!*str)
		return (ft_strdup(""));
	start = 0;
	start = trim_vpered(str, set);
	finish = trim_nazad(str, set, str);
	len = finish - start;
	return (ft_substr(str, start, len));
}
