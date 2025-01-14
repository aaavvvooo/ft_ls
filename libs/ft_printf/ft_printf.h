/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amidoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:19:02 by amidoyan          #+#    #+#             */
/*   Updated: 2021/03/07 00:32:24 by amidoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef unsigned long long int	t_ul;
typedef struct	s_flags
{
	int star;
	int	minus;
	int	zero;
	int	dot;
	int	len;
	int	digit;
}				t_flags;

int				ft_isdigit(int c);
int				ft_printf(const char *format, ...);
int				ft_printf_c(va_list argument, t_flags *flag);
int				ft_printf_s(va_list argument, t_flags *flag);
int				ft_printf_p(va_list argument, t_flags *flag);
int				ft_printf_d(va_list argument, t_flags *flag);
int				ft_printf_u(va_list argument, t_flags *flag);
int				ft_printf_hex(va_list argument, t_flags *flag, char format);
int				ft_printf_percent(t_flags *flag);
void			ft_flag_star(va_list argument, t_flags *flag);
void			init(t_flags *flag);
int				ft_putchar(char c);
int				ft_putstr(char *str);
char			*ft_itoaa(int n);
int				int_len(int n);
int				int_len_u(unsigned int n);
int				int_len_x(unsigned int n);
char			*ft_itoa_u(unsigned int n);
int				flag_check_first(const char *format, int i, t_flags *flag,
		va_list arg);
int				flag_check_second(const char *format, int i, t_flags *flag,
		va_list arg);
int				conv_check(const char *format, int i, va_list arg,
		t_flags *flag);
int				ft_d(int a);
int				spaces_setter(t_flags *flag, int a, int zeros);
int				zero_printer(char zero, int spaces);
int				space_printer(int spaces);
int				spaces_setter_x(t_flags *flag, int a, int zeros);
int				spaces_setter_u(t_flags *flag, int a, int zeros);
int				dot_setter(t_flags *flag, char *str);
void			ft_u(unsigned int a);
int				zero_printer_u(char zero, int spaces);
int				int_len_p(t_ul a);

#endif
