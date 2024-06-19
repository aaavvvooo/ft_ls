/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:52:10 by apiloian          #+#    #+#             */
/*   Updated: 2023/01/27 19:01:24 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	d;
	size_t	slen;

	if (n == 0)
		return (0);
	str = (char *)s;
	slen = ft_strlen(str);
	d = (char)c;
	while (--n)
	{
		if (*str != d)
		{
			str++;
			slen--;
		}
		if (*str == d)
			break ;
		if (slen == 0)
			break ;
	}
	if (*str != d)
		return (0);
	return ((void *)str);
}
