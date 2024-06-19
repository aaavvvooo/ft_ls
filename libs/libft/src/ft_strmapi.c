/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:37 by apiloian          #+#    #+#             */
/*   Updated: 2023/01/27 17:35:11 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ns;
	unsigned int	n;
	unsigned int	i;

	if (!s)
		return (0);
	n = ft_strlen(s);
	i = 0;
	ns = malloc(n + 1);
	if (!ns)
		return (0);
	ns[n] = 0;
	while (n--)
	{
		ns[i] = f(i, *s);
		i++;
		s++;
	}
	return (ns);
}
