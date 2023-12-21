/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:21:27 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/17 16:32:49 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static char	*malloc_str(int n);
static char	*get_str_value(int n, char *str);
static char	*reverse_str(char *str);

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc_str(n);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	else
		get_str_value(n, str);
	reverse_str(str);
	return (str);
}

static char	*malloc_str(int n)
{
	int		chars;
	int		abs_n;
	char	*str;

	chars = 1;
	abs_n = n;
	if (n < 0)
	{
		chars++;
		abs_n = -abs_n;
	}
	while (n / 10 != 0)
	{
		chars++;
		n /= 10;
	}
	str = (char *) malloc((chars + 1) * sizeof(char));
	if (str != NULL)
		str[chars] = '\0';
	return (str);
}

static char	*get_str_value(int n, char *str)
{
	int		is_negative;
	long	n_cpy;
	int		i;

	is_negative = 0;
	n_cpy = n;
	if (n_cpy < 0)
	{
		is_negative = 1;
		n_cpy = -n_cpy;
	}
	i = 0;
	while (n_cpy > 0)
	{
		str[i] = (n_cpy % 10) + '0';
		n_cpy = n_cpy / 10;
		i++;
	}
	if (is_negative == 1)
		str[i] = '-';
	return (str);
}

static char	*reverse_str(char *str)
{
	int		len;
	int		i;
	char	swap;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i <= len / 2)
	{
		swap = str[i];
		str[i] = str[len - i];
		str[len - i] = swap;
		i++;
	}
	return (str);
}
