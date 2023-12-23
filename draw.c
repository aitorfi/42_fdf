/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:18:35 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/23 10:19:20 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_tile(int x, int y, t_mlx *mlx, int tile_size);
static t_point	*point_3d_to_2d(t_point *point);

void	draw_image(t_mlx *mlx)
{
	int		tile_size;
	int		y;
	int		x;

	if (mlx->map_data.width > mlx->map_data.height)
		tile_size = FIGURE_SIZE / mlx->map_data.width;
	else
		tile_size = FIGURE_SIZE / mlx->map_data.height;
	y = 0;
	while (y < mlx->map_data.height)
	{
		x = 0;
		while (x < mlx->map_data.width)
		{
			draw_tile(x, y, mlx, tile_size);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

static void	draw_tile(int x, int y, t_mlx *mlx, int tile_size)
{
	t_point	current;
	t_point	right;
	t_point	bottom;

	current = tile_to_screen_coord(x, y, tile_size, mlx->img_data);
	current.z += mlx->map_data.map[(y * mlx->map_data.width) + x];
	point_3d_to_2d(&current);
	if (x < mlx->map_data.width - 1)
	{
		right = tile_to_screen_coord(x + 1, y, tile_size, mlx->img_data);
		right.z += mlx->map_data.map[(y * mlx->map_data.width) + x + 1];
		point_3d_to_2d(&right);
		draw_bresenham_line(mlx, current, right);
	}
	if (y < mlx->map_data.height - 1)
	{
		bottom = tile_to_screen_coord(x, y + 1, tile_size, mlx->img_data);
		bottom.z += mlx->map_data.map[((y + 1) * mlx->map_data.width) + x];
		point_3d_to_2d(&bottom);
		draw_bresenham_line(mlx, current, bottom);
	}
}

t_point	tile_to_screen_coord(int x, int y, int tile_side, t_img_data img_data)
{
	t_point	point;

	point.x = (x - y) * (tile_side / 2);
	point.y = (y + x) * (tile_side / 2);
	point.x += img_data.width / 2;
	point.y += img_data.height / 4;
	point.z = img_data.center.z;
	return (point);
}

void	draw_pixel(t_mlx *mlx, int x, int y, unsigned int color)
{
	int	pixel_index;

	pixel_index = y * mlx->img_data.line_len;
	pixel_index += (x * (mlx->img_data.bits_per_pixel / 8));
	if (x >= 0 && y > 0 && x < mlx->img_data.width && y < mlx->img_data.height)
		*((unsigned int *)(pixel_index + mlx->img_data.pixels)) = color;
	else
		log_error("Warning: Image bitmap overflow.\n");
}

static t_point	*point_3d_to_2d(t_point *point)
{
	point->y -= point->z;
	return (point);
}
