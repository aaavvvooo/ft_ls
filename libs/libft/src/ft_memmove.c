/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:48:30 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/31 13:48:02 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *d, const void *s, size_t len)
{
	size_t		i;
	char		*dest;
	char		*src;

	i = 0;
	dest = (char *)d;
	src = (char *)s;
	if (dest < src)
	{
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (dest > src)
	{
		i = len - 1;
		while (i < len)
		{
			dest[i] = src[i];
			i--;
		}
	}
	return (dest);
}
