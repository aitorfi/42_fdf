/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:38:37 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/21 18:47:33 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fill_line(char *line, int line_num, t_mlx *mlx);

void	fill_map(t_mlx *mlx, int fd)
{
	char	*line;
	int		line_num;

	line_num = 0;
	line = get_next_line(fd);
	if (line == NULL)
		terminate_free(fd, mlx);
	while (line)
	{
		if (!fill_line(line, line_num, mlx))
			terminate_free(fd, mlx, line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			terminate_free(fd, mlx);
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
		}
		line_num++;
	}
}

static int	fill_line(char *line, int line_num, t_mlx *mlx)
{
	char	**values;
	int		i;
	int		j;
	char	*line_end;

	line_end = ft_strchr(line, '\n');
	if (line_end != NULL)
		*line_end = '\0';
	values = ft_split(line, ' ');
	if (values == NULL)
		return (0);
	i = 0;
	j = line_num * mlx->map_data.width;
	while (values[i])
	{
		mlx->map_data.map[j] = ft_atoi(values[i]);
		free(values[i]);
		i++;
		j++;
	}
	free(values);
	return (1);
}
