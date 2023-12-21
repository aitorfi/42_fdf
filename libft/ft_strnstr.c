/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:29:14 by aitorfi           #+#    #+#             */
/*   Updated: 2023/09/17 19:29:04 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (s2[0] == '\0')
		return ((char *) s1);
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		k = i;
		while (s2[j] != '\0')
		{
			if (s1[k] == '\0' || s2[j] != s1[k] || k >= n)
				break ;
			k++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *) &s1[i]);
		i++;
	}
	return (NULL);
}
