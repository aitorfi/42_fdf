/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:35:02 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:36:38 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			print_uint(unsigned int n);
int			print_int(int n);
int			handle_padding(int len, t_pparams *params);
int			handle_precision_padding(int precision_padding);
int			ft_putchar_fd_count(char c, int fd);
static int	count_digits(long n, int precision, int digits);
static void	handle_flags_int(int n, int *chars, int digits, t_pparams *params);

int	do_print_int(int n, t_pparams *params)
{
	int	chars;
	int	digits;
	int	precision_padding;
	int	print_digits;

	chars = 0;
	digits = count_digits(n, params->precision, 0);
	precision_padding = params->precision - digits;
	print_digits = digits;
	if (n < 0 || params->flags.flag_plus == 1 || params->flags.flag_space == 1)
		print_digits++;
	if (precision_padding > 0)
		print_digits += precision_padding;
	handle_flags_int(n, &chars, print_digits, params);
	chars += handle_precision_padding(precision_padding);
	if (params->precision != 0 || n != 0)
		chars += print_int(n);
	if (params->flags.flag_minus == 1)
		chars += handle_padding(print_digits, params);
	return (chars);
}

static void	handle_flags_int(int n, int *chars, int digits, t_pparams *params)
{
	if (params->precision >= 0)
		params->flags.flag_zero = 0;
	if (params->flags.flag_zero == 0 && params->flags.flag_minus == 0)
	{
		*chars += handle_padding(digits, params);
	}
	if (n < 0)
	{
		*chars += ft_putchar_fd_count('-', STDOUT_FILENO);
	}
	else if (params->flags.flag_plus == 1)
	{
		*chars += ft_putchar_fd_count('+', STDOUT_FILENO);
	}
	else if (params->flags.flag_space == 1)
	{
		*chars += ft_putchar_fd_count(' ', STDOUT_FILENO);
	}
	if (params->flags.flag_zero == 1)
	{
		*chars += handle_padding(digits, params);
	}
}

int	do_print_uint(unsigned int n, t_pparams *params)
{
	int	chars;
	int	digits;
	int	precision_padding;
	int	print_digits;

	chars = 0;
	if (params->precision >= 0)
		params->flags.flag_zero = 0;
	digits = count_digits(n, params->precision, 0);
	precision_padding = params->precision - digits;
	print_digits = digits;
	if (precision_padding > 0)
		print_digits += precision_padding;
	if (params->flags.flag_minus == 0)
		chars += handle_padding(print_digits, params);
	chars += handle_precision_padding(precision_padding);
	if (params->precision != 0 || n != 0)
		chars += print_uint(n);
	if (params->flags.flag_minus == 1)
		chars += handle_padding(print_digits, params);
	return (chars);
}

static int	count_digits(long n, int precision, int digits)
{
	if (precision == 0 && n == 0)
		return (0);
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		digits = count_digits(n / 10, precision, digits);
		digits++;
	}
	else
	{
		digits++;
	}
	return (digits);
}
