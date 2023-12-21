/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:36:10 by afidalgo          #+#    #+#             */
/*   Updated: 2023/09/17 14:35:29 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_start(char const *s1, char const *set);
static int	get_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start == -1 || end == -1)
		return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, start, end - start + 1));
}

static int	get_start(char const *s1, char const *set)
{
	int	start;
	int	is_in_set;
	int	i;
	int	j;

	i = 0;
	start = -1;
	while (s1[i] != '\0' && start == -1)
	{
		is_in_set = 0;
		j = 0;
		while (set[j] != '\0' && is_in_set == 0)
		{
			if (s1[i] == set[j])
				is_in_set = 1;
			j++;
		}
		if (is_in_set == 0)
			start = i;
		i++;
	}
	return (start);
}

static int	get_end(char const *s1, char const *set)
{
	int	end;
	int	is_in_set;
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	end = -1;
	while (i >= 0 && end == -1)
	{
		is_in_set = 0;
		j = 0;
		while (set[j] != '\0' && is_in_set == 0)
		{
			if (s1[i] == set[j])
				is_in_set = 1;
			j++;
		}
		if (is_in_set == 0)
			end = i;
		i--;
	}
	return (end);
}
