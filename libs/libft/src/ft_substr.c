/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:20:25 by amidoyan          #+#    #+#             */
/*   Updated: 2023/02/01 15:01:48 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if ((int)start > ft_strlen(s))
		len = 0;
	if ((int)len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
