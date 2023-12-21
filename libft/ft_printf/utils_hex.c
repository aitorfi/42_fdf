/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:33:58 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:37:05 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_putchar_fd_count(char c, int fd);
static int	print_hex_recursive(unsigned long n, int upper, int cs, int depth);
static int	count_hex_digits_recursive(unsigned long n, int digits, int depth);

int	print_hex(unsigned long n, int upper)
{
	return (print_hex_recursive(n, upper, 0, 0));
}

int	count_hex_digits(unsigned long n, int precision)
{
	if (precision == 0 && n == 0)
		return (0);
	return (count_hex_digits_recursive(n, 0, 0));
}

static int	print_hex_recursive(unsigned long n, int upper, int cs, int depth)
{
	int	digit;

	if (n != 0)
	{
		cs = print_hex_recursive(n / 16, upper, cs, depth + 1);
		digit = n % 16;
		if (digit < 10)
			digit += '0';
		else if (upper == 1)
			digit += 'A' - 10;
		else
			digit += 'a' - 10;
		cs += ft_putchar_fd_count(digit, STDOUT_FILENO);
	}
	else if (depth == 0)
	{
		cs += ft_putchar_fd_count('0', STDOUT_FILENO);
	}
	return (cs);
}

static int	count_hex_digits_recursive(unsigned long n, int digits, int depth)
{
	if (n != 0)
		digits = count_hex_digits_recursive(n / 16, digits, depth + 1) + 1;
	if (n == 0 && depth == 0)
		digits++;
	return (digits);
}
