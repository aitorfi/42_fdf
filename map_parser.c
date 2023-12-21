/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:47:59 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/21 18:47:56 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	open_map_file(t_mlx *mlx, char *map_file);

void	parse_map(t_mlx *mlx, char *map_file)
{
	int	fd;

	fd = open_map_file(mlx, map_file);
	set_map_dimensions(mlx, fd);
	mlx->map_data.map = ft_calloc(
			mlx->map_data.width * mlx->map_data.height, sizeof(int));
	if (mlx->map_data.map == NULL)
		terminate_free(fd, mlx);
	close(fd);
	fd = open_map_file(mlx, map_file);
	fill_map(mlx, fd);
	close(fd);
}

static int	open_map_file(t_mlx *mlx, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: %s\n", strerror(errno));
		terminate_free(0, mlx);
	}
	return (fd);
}
