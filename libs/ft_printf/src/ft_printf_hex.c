/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:14:53 by amidoyan          #+#    #+#             */
/*   Updated: 2021/03/07 18:16:57 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_dig(long n, int len, char *base)
{
	int out;

	out = 0;
	if (n < 0)
	{
		out += ft_dig(n * (-1), len, base);
	}
	if (n >= len)
	{
		out += ft_dig(n / len, len, base);
		out += ft_dig(n % len, len, base);
	}
	else
	{
		out += ft_putchar(base[n]);
	}
	return (out);
}

int ft_putnbr_base_x(unsigned int nbr, char format)
{
	long n;
	int i;
	char *base;
	int out;

	i = 0;
	out = 0;
	n = nbr;
	base = (format == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	while (base[i] != '\0')
		i++;
	out += ft_dig(n, i, base);
	return (out);
}

int int_len_x(unsigned int n)
{
	int len;

	len = 0;
	if ((int)n < 0)
		return (8);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		++len;
	}
	return (len);
}

int ft_printf_hex(va_list argument, t_flags *flag, char format)
{
	int out;
	t_ul a;
	int spaces;
	int zeros;
	char zero;

	out = 0;
	zero = ' ';
	a = va_arg(argument, unsigned int);
	zeros = (flag->dot - int_len_x(a) < 0 ? 0 : flag->dot - int_len_x(a));
	spaces = spaces_setter_x(flag, a, zeros);

	if (flag->zero && flag->dot == -1)
		zero = '0';
	if (!flag->minus && spaces > 0 && flag->digit)
		while (spaces--)
			out += ft_putchar(zero);
	while (zeros--)
		out += ft_putchar('0');
	if ((int)a < 0)
		out += ft_putnbr_base_x(4294967295 + a, format);
	else if (!(a == 0 && flag->dot == 0))
		out += ft_putnbr_base_x(a, format);
	if (flag->minus && spaces > 0 && flag->digit)
		out += space_printer(spaces);
	return (out);
}

int spaces_setter_x(t_flags *flag, int a, int zeros)
{
	int x;

	x = 0;
	if (flag->dot == 0 && a == 0)
		x = (flag->digit - zeros);
	else
		x = (flag->digit - int_len_x(a) - zeros);
	return (x);
}
