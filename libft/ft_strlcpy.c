/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:08:55 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/18 18:38:26 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	src_len;

	src_len = ft_strlen(src);
	count = 0;
	if (dstsize != 0)
	{
		while (src[count] && count < dstsize - 1)
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (src_len);
}
