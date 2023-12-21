/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:09:06 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/21 20:48:19 by afidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <errno.h>
# include <string.h>

# define KEY_ESC 53
# define PI 3.14159265358979323846
# define WIN_WIDTH 1000
# define WIN_HEIGHT 750
# define FIGURE_SIZE 500
# define WHITE 0xFFFFFF

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_map
{
	int	*map;
	int	width;
	int	height;
}		t_map;

typedef struct s_img_data
{
	char	*pixels;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		width;
	int		height;
	t_point	center;
}			t_img_data;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img_data	img_data;
	t_map		map_data;
}				t_mlx;

t_mlx	*init_gui(t_mlx *mlx);
void	set_event_hooks(t_mlx *mlx);
int		terminate(void *data);

void	draw_image(t_mlx *mlx);
void	draw_pixel(t_mlx *mlx, int x, int y, unsigned int color);
t_point	tile_to_screen_coord(int x, int y, int tile_side, t_img_data img_data);
// void	draw_bresenham_line(t_mlx *mlx, t_point *src, t_point *dst);
void	draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1);

void	parse_map(t_mlx *mlx, char *map_file);
void	set_map_dimensions(t_mlx *mlx, int fd);
void	fill_map(t_mlx *mlx, int fd);

void	terminate_free(int fd, void *ptr1, ...);
int		degree2radian(int degree);
void	log_error(char *msg);
#endif
