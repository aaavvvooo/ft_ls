/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:48:11 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/31 13:48:36 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src;

	i = 0;
	dest = (char *)d;
	src = (char *)s;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
