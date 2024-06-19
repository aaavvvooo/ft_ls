/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:58:42 by amidoyan          #+#    #+#             */
/*   Updated: 2021/03/08 00:49:31 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				int_len_u(unsigned int n)
{
	int len;

	len = 0;
	if ((int)n < 0)
		n *= (-1);
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char			*ft_itoa_u(unsigned int n)
{
	int		len;
	char	*res;
	long	nbr;

	nbr = n;
	len = int_len_u(nbr);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= (-1);
	}
	else if (nbr == 0)
	{
		res[0] = '0';
		res[++len] = '\0';
	}
	while (len > 0 && nbr != 0)
	{
		--len;
		res[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

int				ft_printf_u(va_list argument, t_flags *flag)
{
	int				a[4];
	char			zero;

	a[0] = 0;
	zero = ' ';
	a[2] = va_arg(argument, unsigned int);
	a[3] = (flag->dot - int_len_u(a[2]) < 0 ? 0 : flag->dot - int_len_u(a[2]));
	a[1] = spaces_setter_u(flag, a[2], a[3]);
	if (flag->zero && flag->dot == -1)
		zero = '0';
	if ((a[2] < 0 && zero == '0'))
		ft_u(a[2]);
	if (!flag->minus && a[1] > 0 && flag->digit)
		a[0] += zero_printer_u(zero, a[1]);
	if (a[2] < 0 && zero == ' ')
		ft_u(a[2]);
	while (a[3]--)
		a[0] += ft_putchar('0');
	if (flag->dot != 0 || a[2] != 0)
		a[0] += ft_putstr(ft_itoa_u(a[2]));
	if (flag->minus && a[1] > 0 && flag->digit)
		a[0] += space_printer(a[1]);
	return (a[0]);
}

int				spaces_setter_u(t_flags *flag, int a, int zeros)
{
	if (flag->dot == 0 && a == 0)
		return (flag->digit - zeros);
	return (flag->digit - int_len_u(a) - zeros);
}

void			ft_u(unsigned int a)
{
	a = -a;
}
