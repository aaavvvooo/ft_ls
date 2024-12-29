/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:02:15 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/16 15:02:20 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*src;
	char	*str;

	src = (char *)s;
	str = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (str == 0)
	{
		return (0);
	}
	ft_strcpy(str, src);
	return (str);
}
