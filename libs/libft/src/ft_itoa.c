/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <amidoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:19:17 by amidoyan          #+#    #+#             */
/*   Updated: 2023/03/03 16:44:14 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	len(int n)
{
	int	size;

	size = 0;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

int	minus(int n, char *number, int size)
{
	if (n < 0)
	{
		n *= -1;
		number[0] = '-';
	}
	number[size] = '\0';
	return (n);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		size;

	size = len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		size++;
	number = malloc(size + 1);
	if (!number)
		return (0);
	n = minus(n, number, size);
	while (size--)
	{
		if (n < 10)
		{
			number[size] = n % 10 + '0';
			n /= 10;
			break ;
		}
		number[size] = n % 10 + '0';
		n /= 10;
	}
	return (number);
}
