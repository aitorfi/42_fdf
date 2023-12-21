/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:47:53 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:37:01 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	set_flag(char c, t_flags *flags);
static void	init_flags(t_flags *flags);

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+');
}

const char	*set_flags(const char *format, t_flags *flags)
{
	int	i;

	init_flags(flags);
	i = 1;
	while (is_flag(format[i]))
	{
		set_flag(format[i], flags);
		i++;
	}
	return (&format[i]);
}

static void	init_flags(t_flags *flags)
{
	flags->flag_hash = 0;
	flags->flag_minus = 0;
	flags->flag_period = 0;
	flags->flag_plus = 0;
	flags->flag_space = 0;
	flags->flag_zero = 0;
}

static void	set_flag(char c, t_flags *flags)
{
	if (c == '-')
	{
		flags->flag_minus = 1;
		flags->flag_zero = 0;
	}
	else if (c == '0' && flags->flag_minus == 0)
		flags->flag_zero = 1;
	else if (c == '.')
		flags->flag_period = 1;
	else if (c == '#')
		flags->flag_hash = 1;
	else if (c == ' ' && flags->flag_plus == 0)
		flags->flag_space = 1;
	else if (c == '+')
	{
		flags->flag_plus = 1;
		flags->flag_space = 0;
	}
}
