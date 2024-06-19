/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:51:27 by apiloian          #+#    #+#             */
/*   Updated: 2023/01/31 18:19:48 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	tlen;
	void	*p;

	p = (void *)str;
	if (!*to_find)
		return ((char *)str);
	tlen = ft_strlen(to_find);
	while (tlen)
	{
		if (len != 0)
		{
			if (!*str || tlen > len--)
				return (0);
		}
		else
		{
			if (!p || tlen > len--)
				return (0);
		}
		if (!ft_strncmp(str, to_find, tlen))
			return ((char *)str);
		str++;
	}
	return (0);
}
