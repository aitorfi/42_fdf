/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:33:07 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/23 10:27:21 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_low(t_mlx *mlx, t_point *src, t_point *dst);
static void	draw_line_high(t_mlx *mlx, t_point *src, t_point *dst);

void	draw_bresenham_line(t_mlx *mlx, t_point src, t_point dst)
{
	if (abs(dst.y - src.y) < abs(dst.x - src.x))
	{
		if (src.x > dst.x)
			draw_line_low(mlx, &dst, &src);
		else
			draw_line_low(mlx, &src, &dst);
	}
	else
	{
		if (src.y > dst.y)
			draw_line_high(mlx, &dst, &src);
		else
			draw_line_high(mlx, &src, &dst);
	}
}

static void	draw_line_low(t_mlx *mlx, t_point *src, t_point *dst)
{
	t_point	delta_point;
	int		y_increment;
	int		y;
	int		diff;

	delta_point.x = dst->x - src->x;
	delta_point.y = abs(dst->y - src->y);
	y_increment = 1;
	if (dst->y < src->y)
		y_increment = -1;
	diff = (2 * delta_point.y) - delta_point.x;
	y = src->y;
	while (src->x <= dst->x)
	{
		draw_pixel(mlx, src->x, y, WHITE);
		if (diff > 0)
		{
			y += y_increment;
			diff += 2 * (delta_point.y - delta_point.x);
		}
		else
			diff += 2 * delta_point.y;
		src->x++;
	}
}

static void	draw_line_high(t_mlx *mlx, t_point *src, t_point *dst)
{
	t_point	delta_point;
	int		x_increment;
	int		diff;
	int		x;

	delta_point.x = abs(dst->x - src->x);
	delta_point.y = dst->y - src->y;
	x_increment = 1;
	if (dst->x < src->x)
		x_increment = -1;
	diff = (2 * delta_point.x) - delta_point.y;
	x = src->x;
	while (src->y < dst->y)
	{
		draw_pixel(mlx, x, src->y, WHITE);
		if (diff > 0)
		{
			x += x_increment;
			diff += (2 * (delta_point.x - delta_point.y));
		}
		else
			diff += 2 * delta_point.x;
		src->y++;
	}
}
