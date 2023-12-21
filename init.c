/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:32:01 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/17 14:46:48 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	*init_connection(t_mlx *mlx);
static t_mlx	*init_window(t_mlx *mlx);
static t_mlx	*init_image(t_mlx *mlx);
static t_mlx	*init_image_data(t_mlx *mlx);

t_mlx	*init_gui(t_mlx *mlx)
{
	mlx = init_connection(mlx);
	mlx = init_window(mlx);
	mlx = init_image(mlx);
	return (mlx);
}

static t_mlx	*init_connection(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		terminate_free(0, mlx->map_data.map, mlx);
	return (mlx);
}

static t_mlx	*init_window(t_mlx *mlx)
{
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (mlx->win_ptr == NULL)
		terminate_free(0, mlx->map_data.map, mlx->mlx_ptr, mlx);
	return (mlx);
}

static t_mlx	*init_image(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img_ptr == NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		terminate_free(0, mlx->map_data.map, mlx->mlx_ptr, mlx);
	}
	mlx = init_image_data(mlx);
	return (mlx);
}

static t_mlx	*init_image_data(t_mlx *mlx)
{
	mlx->img_data.width = WIN_WIDTH;
	mlx->img_data.height = WIN_HEIGHT;
	mlx->img_data.pixels = mlx_get_data_addr(
			mlx->img_ptr,
			&mlx->img_data.bits_per_pixel,
			&mlx->img_data.line_len,
			&mlx->img_data.endian);
	mlx->img_data.center.x = mlx->img_data.width / 2;
	mlx->img_data.center.y = mlx->img_data.height / 2;
	mlx->img_data.center.z = 0;
	return (mlx);
}
