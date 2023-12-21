/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:10:29 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:36:56 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_fd_count(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	ft_putchar_fd_count(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}
