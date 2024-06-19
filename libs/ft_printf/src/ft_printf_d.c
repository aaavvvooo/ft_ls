/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:26:10 by amidoyan          #+#    #+#             */
/*   Updated: 2021/03/07 01:27:04 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_printf_d(va_list argument, t_flags *flag)
{
	int a[4];
	char zero;

	a[0] = 0;
	zero = ' ';
	a[2] = va_arg(argument, int);
	a[3] = (flag->dot - int_len(a[2]) < 0 ? 0 : flag->dot - int_len(a[2]));
	a[1] = spaces_setter(flag, a[2], a[3]);
	if (flag->zero && flag->dot == -1)
		zero = '0';
	if (a[2] < 0)
		--a[1];
	if ((a[2] < 0 && zero == '0'))
		a[0] += ft_d(a[2]);
	if (!flag->minus && a[1] > 0 && flag->digit)
		a[0] += zero_printer(zero, a[1]);
	if (a[2] < 0 && zero == ' ')
		a[0] += ft_d(a[2]);
	while (a[3]--)
		a[0] += ft_putchar('0');
	if (flag->dot != 0 || a[2] != 0)
		a[0] += ft_putstr(ft_itoa(a[2]));
	if (flag->minus && a[1] > 0 && flag->digit)
		a[0] += space_printer(a[1]);
	return (a[0]);
}

int ft_d(int a)
{
	int out;

	out = 0;
	out += ft_putchar('-');
	a = -a;
	return (out);
}

int spaces_setter(t_flags *flag, int a, int zeros)
{
	if (flag->dot == 0 && a == 0)
		return (flag->digit - zeros);
	return (flag->digit - int_len(a) - zeros);
}

int space_printer(int spaces)
{
	int out;

	out = 0;
	while (spaces--)
		out += ft_putchar(' ');
	return (out);
}

int zero_printer(char zero, int spaces)
{
	int out;

	out = 0;
	while (spaces--)
		out += ft_putchar(zero);
	return (out);
}
