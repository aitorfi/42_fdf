/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:00:57 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/16 13:32:12 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	dest_len = i;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len == dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dest_len + i + 1) < dstsize)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
