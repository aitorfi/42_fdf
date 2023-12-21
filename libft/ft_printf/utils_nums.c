/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:46:31 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:37:09 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_putchar_fd_count(char c, int fd);
static int	print_uint_recursive(unsigned int n, int chars);
static int	print_int_recursive(int n, int chars);

int	print_uint(unsigned int n)
{
	return (print_uint_recursive(n, 0));
}

static int	print_uint_recursive(unsigned int n, int chars)
{
	unsigned long	n_cpy;

	n_cpy = n;
	if (n_cpy >= 10)
	{
		chars = print_uint_recursive(n_cpy / 10, chars);
		ft_putchar_fd((n_cpy % 10) + '0', STDOUT_FILENO);
		chars++;
	}
	else
	{
		ft_putchar_fd(n_cpy + '0', STDOUT_FILENO);
		chars++;
	}
	return (chars);
}

int	print_int(int n)
{
	return (print_int_recursive(n, 0));
}

static int	print_int_recursive(int n, int chars)
{
	long	n_cpy;

	n_cpy = n;
	if (n_cpy < 0)
		n_cpy = -n_cpy;
	if (n_cpy >= 10)
	{
		chars = print_int_recursive(n_cpy / 10, chars);
		ft_putchar_fd((n_cpy % 10) + '0', STDOUT_FILENO);
		chars++;
	}
	else
	{
		chars += ft_putchar_fd_count(n_cpy + '0', STDOUT_FILENO);
	}
	return (chars);
}
