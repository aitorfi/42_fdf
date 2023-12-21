/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:36:13 by afidalgo          #+#    #+#             */
/*   Updated: 2023/11/04 13:20:54 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <string.h>

char	*get_line_remainder(char *buffer)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	remainder = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (remainder == NULL)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[i] != '\0')
		i++;
	j = 0;
	while (buffer[i] != '\0')
	{
		remainder[j] = buffer[i];
		i++;
		j++;
	}
	remainder[j] = '\0';
	free(buffer);
	return (remainder);
}

char	*split_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		line = malloc((i + 2) * sizeof(char));
	else
		line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i + 1] = '\0';
	return (line);
}

char	*join_buffer(int bytes, char *buffer, char *remainder)
{
	char	*del;

	if (bytes == -1)
	{
		if (remainder != NULL)
			free(remainder);
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	if (remainder == NULL)
		remainder = ft_strjoin("", buffer);
	else
	{
		del = remainder;
		remainder = ft_strjoin(remainder, buffer);
		free(del);
	}
	if (remainder == NULL)
	{
		free(buffer);
		return (NULL);
	}
	return (remainder);
}

char	*read_line(int fd, char *remainder)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		if (remainder != NULL)
			free(remainder);
		return (NULL);
	}
	bytes = 1;
	while (bytes != 0 && ft_strchr(remainder, '\n') == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		remainder = join_buffer(bytes, buffer, remainder);
		if (remainder == NULL)
			return (NULL);
	}
	free(buffer);
	if (bytes == 0 && !remainder[0])
	{
		free(remainder);
		return (NULL);
	}
	return (remainder);
}

char	*get_next_line_bonus(int fd)
{
	char		*line;
	static char	*remainder[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder[fd] == NULL || ft_strchr(remainder[fd], '\n') == NULL)
		remainder[fd] = read_line(fd, remainder[fd]);
	if (remainder[fd] == NULL)
		return (NULL);
	line = split_line(remainder[fd]);
	if (line == NULL)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	remainder[fd] = get_line_remainder(remainder[fd]);
	if (remainder[fd] == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int		i = 0;

// 	fd = open("./tests/giant_line.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	printf("\n\n");
// 	return (0);
// }
