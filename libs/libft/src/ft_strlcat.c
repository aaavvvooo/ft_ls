/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:08 by apiloian          #+#    #+#             */
/*   Updated: 2023/01/31 13:48:05 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *s, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	clen;
	size_t	remain;

	slen = ft_strlen(s);
	if (dstsize == 0)
		return (slen);
	remain = dstsize;
	while (*dst && remain)
	{
		dst++;
		remain--;
	}
	dlen = dstsize - remain;
	if (remain)
	{
		clen = remain - 1;
		if (slen < clen)
			clen = slen;
		ft_memcpy(dst, s, clen);
		dst[clen] = '\0';
	}
	return (dlen + slen);
}
