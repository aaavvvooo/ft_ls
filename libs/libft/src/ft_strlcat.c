/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:08 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/31 13:48:05 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char **dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*d;

	i = 0;
	j = 0;
	d = *dst;
	while (d[i] && i < size)
	{
		i++;
	}
	while (src[j] && (i + j + 1) <= size)
	{
		d[i + j] = src[j];
		j++;
	}
	if (i < size)
		d[i + j] = '\0';
	return (i + ft_strlen(src));
}