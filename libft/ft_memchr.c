/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:37:56 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/18 19:08:00 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	int				i;

	ps = (unsigned char *) s;
	i = 0;
	while (n > 0)
	{
		if (ps[i] == (unsigned char) c)
			return (&ps[i]);
		i++;
		n--;
	}
	return (0);
}
