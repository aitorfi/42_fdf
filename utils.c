/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:38:29 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/18 20:13:29 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "fdf.h"

void	terminate_free(int fd, void *ptr1, ...)
{
	va_list	args;
	void	*ptr;

	if (fd)
		close(fd);
	va_start(args, ptr1);
	free(ptr1);
	ptr = va_arg(args, void *);
	while (ptr)
	{
		free(ptr);
		ptr = va_arg(args, void *);
	}
	va_end(args);
	if (errno)
		ft_printf("Error: %s\n", strerror(errno));
	else
		ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	degree2radian(int degree)
{
	return (degree * PI / 180);
}

void	log_error(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
}
