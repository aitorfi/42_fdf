/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:33:46 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/17 16:41:08 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*ret;
	int		i;

	len = ft_strlen(s);
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
