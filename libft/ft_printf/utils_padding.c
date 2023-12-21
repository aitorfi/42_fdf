/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:53:47 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:37:13 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar_fd_count(char c, int fd);

int	handle_padding(int len, t_pparams *params)
{
	int	chars;

	chars = 0;
	while (len < params->width)
	{
		if (params->flags.flag_zero == 1 && params->flags.flag_minus == 0)
			ft_putchar_fd('0', STDOUT_FILENO);
		else
			ft_putchar_fd(' ', STDOUT_FILENO);
		len++;
		chars++;
	}
	return (chars);
}

int	handle_precision_padding(int precision_padding)
{
	int	chars;

	chars = 0;
	while (precision_padding > 0)
	{
		chars += ft_putchar_fd_count('0', STDOUT_FILENO);
		precision_padding--;
	}
	return (chars);
}
