/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:34:31 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:36:07 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			handle_padding(int len, t_pparams *params);
int			ft_putchar_fd_count(char c, int fd);
static int	handle_precision_str(char *str, t_pparams *params);

int	print_char(char c, t_pparams *params)
{
	int	chars;

	chars = 0;
	if (params->flags.flag_minus == 0)
		chars += handle_padding(1, params);
	chars += ft_putchar_fd_count(c, STDOUT_FILENO);
	if (params->flags.flag_minus == 1)
		chars += handle_padding(1, params);
	return (chars);
}

int	print_str(char *str, t_pparams *params)
{
	int	chars;

	if (str == NULL)
		return (print_str("(null)", params));
	if (ft_strlen(str) > (size_t) params->precision)
		return (handle_precision_str(str, params));
	chars = ft_strlen(str);
	if (params->flags.flag_minus == 0)
		chars += handle_padding(chars, params);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (params->flags.flag_minus == 1)
		chars += handle_padding(chars, params);
	return (chars);
}

static int	handle_precision_str(char *str, t_pparams *params)
{
	int	chars;

	str = ft_substr(str, 0, params->precision);
	if (str == NULL)
	{
		free(str);
		return (-1);
	}
	chars = print_str(str, params);
	free(str);
	return (chars);
}
