/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:25:37 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/16 12:47:26 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < n && ret == 0 && s1[i] != '\0' && s2[i] != '\0')
	{
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (i < n && ret == 0 && s1[i] == '\0')
		return ((unsigned char)s2[i] * -1);
	if (i < n && ret == 0 && s2[i] == '\0')
		return ((unsigned char)s1[i]);
	return (ret);
}
