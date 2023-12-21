/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:11:36 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:09:27 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	join_len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_len = s1_len + s2_len + 1;
	join = (char *) malloc(join_len * sizeof(char));
	if (join == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcat(join, s2, join_len);
	return (join);
}
