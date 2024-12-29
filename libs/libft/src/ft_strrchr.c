/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:51:00 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/31 14:18:57 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;
	int		len;

	buf = (char *)s;
	len = ft_strlen(buf);
	while (*buf)
		buf++;
	while (*buf != (char)c && len--)
		buf--;
	if (*buf == (char)c)
		return (buf);
	else
		return (NULL);
}
