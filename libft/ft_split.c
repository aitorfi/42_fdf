/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:48:10 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/16 18:49:47 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_num_of_words(char const *s, char c, int len);
static char	**get_words(char const *s, char c, char **ret);
static char	**malloc_for_words(char const *s, char c, char **ret, int words);

char	**ft_split(char const *s, char c)
{
	int		num_of_words;
	char	**ret;
	int		len;
	int		i;

	len = ft_strlen(s);
	num_of_words = get_num_of_words(s, c, len);
	ret = (char **) malloc((num_of_words + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	ret[num_of_words] = NULL;
	if (malloc_for_words(s, c, ret, num_of_words) == NULL)
	{
		i = 0;
		while (ret[i])
		{
			free(ret[i]);
			i++;
		}
		free(ret);
		return (NULL);
	}
	get_words(s, c, ret);
	return (ret);
}

static int	get_num_of_words(char const *s, char c, int len)
{
	int	num_of_words;
	int	i;

	num_of_words = 0;
	i = 0;
	while (i < len)
	{
		if (i > 0 && s[i] == c && s[i - 1] != c)
			num_of_words++;
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		num_of_words++;
	return (num_of_words);
}

static char	**malloc_for_words(char const *s, char c, char **ret, int words)
{
	int	i;
	int	j;
	int	chars;

	i = 0;
	j = 0;
	chars = 0;
	while (j < words)
	{
		if (s[i] != c && s[i] != '\0')
			chars++;
		if (i > 0 && s[i - 1] != c && (s[i] == c || s[i] == '\0'))
		{
			ret[j] = (char *) malloc((chars + 1) * sizeof(char));
			if (ret[j] == NULL)
				return (NULL);
			ret[j][chars] = '\0';
			j++;
			chars = 0;
		}
		i++;
	}
	return (ret);
}

static char	**get_words(char const *s, char c, char **ret)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ret[j][k] = s[i];
			k++;
		}
		if (i > 0 && s[i] == c && s[i - 1] != c)
		{
			j++;
			k = 0;
		}
		i++;
	}
	return (ret);
}
