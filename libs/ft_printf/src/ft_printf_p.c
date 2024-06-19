/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:52:19 by amidoyan          #+#    #+#             */
/*   Updated: 2021/03/07 18:53:54 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_dig_p(t_ul n, int len, char *base)
{
	int out;

	out = 0;
	if (n >= (t_ul)len)
	{
		out += ft_dig_p(n / len, len, base);
		out += ft_dig_p(n % len, len, base);
	}
	else
	{
		out += ft_putchar(base[n]);
	}
	return (out);
}

int ft_putnbr_base_p(t_ul nbr)
{
	int i;
	t_ul n;
	int out;
	char *base;

	i = 0;
	out = 0;
	n = nbr;
	base = "0123456789abcdef";
	while (base[i] != '\0')
		i++;
	out += ft_dig_p(n, i, base);
	return (out);
}

int ft_printf_p(va_list argument, t_flags *flag)
{
	t_ul a;
	int out;
	int spaces;

	out = 0;
	a = (t_ul)va_arg(argument, void *);
	spaces = flag->digit - int_len_p(a) - 2;
	if (spaces > 0 && !flag->minus)
		while (spaces--)
			out += ft_putchar(' ');
	out += ft_putstr("0x");
	out += ft_putnbr_base_p(a);
	if (flag->minus == 1 && spaces > 0)
		while (spaces--)
			out += ft_putchar(' ');
	return (out);
}

int int_len_p(t_ul a)
{
	int len;

	len = 0;
	if ((int)a < 0)
		return (8);
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a /= 16;
		++len;
	}
	return (len);
}