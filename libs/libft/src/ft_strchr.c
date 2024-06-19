/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:50:06 by apiloian          #+#    #+#             */
/*   Updated: 2023/01/24 14:49:58 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buf;
	char	d;

	buf = (char *)s;
	d = (char)c;
	while (*buf != d && *buf)
	{
		buf++;
	}
	if (*buf == d)
		return (buf);
	else
		return (0);
}
