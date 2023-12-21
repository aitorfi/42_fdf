/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:50:28 by aitorfi           #+#    #+#             */
/*   Updated: 2023/09/17 13:58:50 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	total_size;

	total_size = count * size;
	p = (char *)malloc(total_size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, total_size);
	return ((void *) p);
}
