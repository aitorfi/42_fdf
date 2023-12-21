/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:55:26 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/16 13:34:39 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p_dst;
	const char	*p_src;
	size_t		i;

	p_dst = dst;
	p_src = src;
	i = 0;
	if (p_dst < p_src)
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	else if (p_dst > p_src)
	{
		while (i < len)
		{
			p_dst[len - 1 - i] = p_src[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
