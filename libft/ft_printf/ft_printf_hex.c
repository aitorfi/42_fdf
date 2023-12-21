/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:33:50 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:36:33 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			print_hex(unsigned long n, int upper);
int			count_hex_digits(unsigned long n, int precision);
int			handle_padding(int len, t_pparams *params);
int			handle_precision_padding(int precision_padding);
int			ft_putchar_fd_count(char c, int fd);
int			ft_putstr_fd_count(char *str, int fd);
static int	handle_flags(unsigned long n, int upper, int *d, t_pparams *p);

int	do_print_hex(unsigned long n, int is_upper, t_pparams *params)
{
	int	chars;
	int	digits;
	int	precision_padding;
	int	print_digits;

	chars = 0;
	if (params->precision >= 0)
		params->flags.flag_zero = 0;
	digits = count_hex_digits(n, params->precision);
	precision_padding = params->precision - digits;
	print_digits = digits;
	if (precision_padding > 0)
		print_digits += precision_padding;
	chars += handle_flags(n, is_upper, &print_digits, params);
	chars += handle_precision_padding(precision_padding);
	if (params->precision != 0 || n != 0)
		chars += print_hex(n, is_upper);
	if (params->flags.flag_minus == 1)
		chars += handle_padding(print_digits, params);
	return (chars);
}

static int	handle_flags(unsigned long n, int upper, int *d, t_pparams *p)
{
	int	chars;

	chars = 0;
	if (p->flags.flag_hash == 1 && n != 0)
	{
		*d = *d + 2;
		if (p->flags.flag_zero == 0 && p->flags.flag_minus == 0)
			chars += handle_padding(*d, p);
		if (upper == 1)
			chars += ft_putstr_fd_count("0X", STDOUT_FILENO);
		else
			chars += ft_putstr_fd_count("0x", STDOUT_FILENO);
		if (p->flags.flag_zero == 1)
			chars += handle_padding(*d, p);
	}
	else if (p->flags.flag_minus != 1)
		chars += handle_padding(*d, p);
	return (chars);
}

int	print_pointer_hex(void *p, t_pparams *params)
{
	int	chars;
	int	digits;

	chars = 0;
	digits = count_hex_digits((unsigned long) p, params->precision) + 2;
	if (params->flags.flag_minus == 1)
	{
		chars += ft_putstr_fd_count("0x", STDOUT_FILENO);
		chars += print_hex((unsigned long) p, 0);
		chars += handle_padding(digits, params);
	}
	else
	{
		chars += handle_padding(digits, params);
		chars += ft_putstr_fd_count("0x", STDOUT_FILENO);
		chars += print_hex((unsigned long) p, 0);
	}
	return (chars);
}
