/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:52:26 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/31 13:48:44 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			counter;
	unsigned char	*s1;
	unsigned char	*s2;

	if (n <= 0)
		return (0);
	counter = 1;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*s1 == *s2 && counter < n)
	{
		s1++;
		s2++;
		counter++;
	}
	return (*s1 - *s2);
}
