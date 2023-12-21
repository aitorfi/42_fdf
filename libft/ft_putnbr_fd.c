/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:24:31 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/17 17:53:26 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_cpy;

	n_cpy = n;
	if (n_cpy < 0)
	{
		ft_putchar_fd('-', fd);
		n_cpy = -n_cpy;
	}
	if (n_cpy >= 10)
	{
		ft_putnbr_fd(n_cpy / 10, fd);
		ft_putchar_fd((n_cpy % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd(n_cpy + '0', fd);
	}
}
