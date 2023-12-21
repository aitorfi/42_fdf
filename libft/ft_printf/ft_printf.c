/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:02:52 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:36:43 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_putchar_fd_count(char c, int fd);
int			print_char(char c, t_pparams *params);
int			print_str(char *str, t_pparams *params);
int			do_print_int(int n, t_pparams *params);
int			do_print_uint(unsigned int n, t_pparams *params);
int			do_print_hex(unsigned long n, int is_upper, t_pparams *params);
int			print_pointer_hex(void *p, t_pparams *params);
const char	*set_flags(const char *format, t_flags *flags);
int			is_flag(char c);
int			handle_fspec(const char *format, int *cs, va_list a);
int			is_format_spec(char c);
int			print_fspec(char format, int *cs, va_list args, t_pparams *params);
void		get_params(const char *format, t_pparams *params);

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			printed_chars;
	int			i;
	int			tmp;

	va_start(args, format);
	printed_chars = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			tmp = handle_fspec(&format[i], &printed_chars, args);
			if (tmp < 0)
				return (tmp);
			i += tmp;
		}
		else
		{
			printed_chars += ft_putchar_fd_count(format[i], STDOUT_FILENO);
			i++;
		}
	}
	va_end(args);
	return (printed_chars);
}

void	get_params(const char *format, t_pparams *params)
{
	format = set_flags(format, &params->flags);
	params->width = 0;
	while (ft_isdigit(*format))
	{
		params->width *= 10;
		params->width += *format - '0';
		format++;
	}
	params->precision = -1;
	if (*format == '.')
	{
		params->precision = 0;
		format++;
		while (ft_isdigit(*format))
		{
			params->precision *= 10;
			params->precision += *format - '0';
			format++;
		}
	}
}

int	handle_fspec(const char *format, int *cs, va_list a)
{
	t_pparams	params;
	int			i;
	int			tmp;

	i = 1;
	get_params(&format[0], &params);
	while (is_flag(format[i]))
		i++;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.')
	{
		i++;
		while (ft_isdigit(format[i]))
			i++;
	}
	if (is_format_spec(format[i]))
	{
		tmp = print_fspec(format[i], cs, a, &params);
		if (tmp < 0)
			return (tmp);
		i++;
	}
	return (i);
}

int	is_format_spec(char c)
{
	return (c == '%' || c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

int	print_fspec(char format, int *cs, va_list args, t_pparams *params)
{
	int	tmp;

	if (format == 'c')
		*cs += print_char(va_arg(args, int), params);
	else if (format == '%')
		*cs += print_char(format, params);
	else if (format == 's')
	{
		tmp = print_str(va_arg(args, char *), params);
		if (tmp < 0)
			return (tmp);
		*cs += tmp;
	}
	else if (format == 'i' || format == 'd')
		*cs += do_print_int(va_arg(args, int), params);
	else if (format == 'u')
		*cs += do_print_uint(va_arg(args, unsigned int), params);
	else if (format == 'x')
		*cs += do_print_hex(va_arg(args, unsigned int), 0, params);
	else if (format == 'X')
		*cs += do_print_hex(va_arg(args, unsigned int), 1, params);
	else if (format == 'p')
		*cs += print_pointer_hex(va_arg(args, void *), params);
	return (1);
}
