/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:51:36 by amidoyan          #+#    #+#             */
/*   Updated: 2023/01/24 14:49:35 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
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
		if (*s1 == '\0')
		{
			break ;
		}
		s1++;
		s2++;
		counter++;
	}
	return (*s1 - *s2);
}
