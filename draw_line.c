/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:33:07 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/21 20:48:09 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_low(t_mlx *mlx, int x0, int y0, int x1, int y1);
// static void	draw_line_low(t_mlx *mlx, t_point *src, t_point *dst);
static void	draw_line_high(t_mlx *mlx, int x0, int y0, int x1, int y1);
// static void	draw_line_high(t_mlx *mlx, t_point *src, t_point *dst);

void	draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			draw_line_low(mlx, x1, y1, x0, y0);
		else
			draw_line_low(mlx, x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			draw_line_high(mlx, x1, y1, x0, y0);
		else
			draw_line_high(mlx, x0, y0, x1, y1);
	}
}

// void	draw_bresenham_line(t_mlx *mlx, t_point *src, t_point *dst)
// {
// 	if (abs(dst->y - src->y) < abs(dst->x - src->x))
// 	{
// 		if (src->x > dst->x)
// 			draw_line_low(mlx, dst->x, dst->y, src->x, src->x);
// 			// draw_line_low(mlx, dst, src);
// 		else
// 			draw_line_low(mlx, src->x, src->y, dst->x, dst->y);
// 			// draw_line_low(mlx, src, dst);
// 	}
// 	else
// 	{
// 		if (src->y > dst->y)
// 			draw_line_high(mlx, dst->x, dst->y, src->x, src->y);
// 			// draw_line_high(mlx, dst, src);
// 		else
// 			draw_line_high(mlx, src->x, src->y, dst->x, dst->y);
// 			// draw_line_high(mlx, src, dst);
// 	}
// }

static void	draw_line_low(t_mlx *mlx, int x0, int y0, int x1, int y1)
{
	int	dx = x1 - x0;
    int	dy = y1 - y0;
    int	yi = 1;
    if (dy < 0)
	{
		yi = -1;
        dy = -dy;
	}
    int D = (2 * dy) - dx;
    int y = y0;

    while (x0 <= x1)
	{
		draw_pixel(mlx, x0, y, WHITE);
        if (D > 0)
		{
			y = y + yi;
            D = D + (2 * (dy - dx));
		}
        else
            D = D + 2*dy;
		x0++;
	}
}

// static void	draw_line_low(t_mlx *mlx, t_point *src, t_point *dst)
// {
// 	t_point	delta_point;
// 	int		y_increment;
// 	int		y;
// 	int		diff;

// 	delta_point.x = dst->x - src->x;
// 	delta_point.y = abs(dst->y - src->y);
// 	y_increment = 1;
// 	if (dst->y < src->y)
// 		y_increment = -1;
//     diff = (2 * delta_point.y) - delta_point.x;
//     y = src->y;
//     while (src->x <= dst->x)
// 	{
// 		draw_pixel(mlx, src->x, y, WHITE);
//         if (diff > 0)
// 		{
// 			y += y_increment;
//             diff += 2 * (delta_point.y - delta_point.x);
// 		}
//         else
//             diff += 2 * delta_point.y;
// 		src->x++;
// 	}
// }

// static void	draw_line_high(t_mlx *mlx, t_point *src, t_point *dst)
static void	draw_line_high(t_mlx *mlx, int x0, int y0, int x1, int y1)
{
	int	dx = x1 - x0;
    int	dy = y1 - y0;
    int	xi = 1;
    if (dx < 0)
	{
		xi = -1;
        dx = -dx;
	}
    int	D = (2 * dx) - dy;
    int	x = x0;

    while (y0 < y1)
	{
		draw_pixel(mlx, x, y0, WHITE);
        if (D > 0)
		{
			x = x + xi;
            D = D + (2 * (dx - dy));	
		}
        else
            D = D + 2*dx;
		y0++;
	}
}

// static void	draw_line_high(t_mlx *mlx, t_point *src, t_point *dst)
// {
// 	t_point	delta_point;
// 	int		x_increment;
// 	int		diff;
// 	int		x;

// 	delta_point.x = abs(dst->x - src->x);
// 	delta_point.y = dst->y - src->y;
//     x_increment = 1;
//     if (dst->x < src->x)
// 		x_increment = -1;
//     diff = (2 * delta_point.x) - delta_point.y;
//     x = src->x;
//     while (src->y < dst->y)
// 	{
// 		draw_pixel(mlx, x, src->y, WHITE);
//         if (diff > 0)
// 		{
// 			x = x + x_increment;
//             diff += (2 * (delta_point.x - delta_point.y));	
// 		}
//         else
//             diff += 2 * delta_point.x;
// 		src->y++;
// 	}
// }
