/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_dimensions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:36:35 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/21 18:47:44 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_map_width(t_mlx *mlx, char *line, int fd);

void	set_map_dimensions(t_mlx *mlx, int fd)
{
	char	*line;

	mlx->map_data.height = 0;
	mlx->map_data.width = 0;
	line = get_next_line(fd);
	if (line == NULL)
		terminate_free(fd, mlx);
	set_map_width(mlx, line, fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			terminate_free(fd, mlx);
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
		}
		mlx->map_data.height++;
	}
}

static void	set_map_width(t_mlx *mlx, char *line, int fd)
{
	char	**values;

	*ft_strchr(line, '\n') = '\0';
	values = ft_split(line, ' ');
	if (values == NULL)
		terminate_free(fd, line, mlx);
	while (values[mlx->map_data.width] != NULL)
	{
		free(values[mlx->map_data.width]);
		mlx->map_data.width++;
	}
	free(values);
}
