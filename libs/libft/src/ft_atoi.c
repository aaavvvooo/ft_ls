/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:53:04 by apiloian          #+#    #+#             */
/*   Updated: 2023/01/31 13:49:02 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ' || *str == '+')
	{
		if (*str == '+' && !(ft_isdigit(*(str + 1))))
			return (0);
		str++;
	}
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str)
	{
		if ((*str < '0' || *str > '9'))
			return (res * sign);
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
