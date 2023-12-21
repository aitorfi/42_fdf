/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:07:18 by aitorfi           #+#    #+#             */
/*   Updated: 2023/09/17 19:30:17 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*p;

	len = ft_strlen(s1);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (p == NULL)
	{
		errno = ENOMEM;
	}
	else
	{
		while (len >= 0)
		{
			p[len] = s1[len];
			len--;
		}
	}
	return (p);
}
