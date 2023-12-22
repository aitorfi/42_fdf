/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorfi <aitorfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:33:36 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/22 17:12:34 by aitorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	(void) argv;
	if (argc != 2)
	{
		write(STDERR_FILENO, "Error: Numero incorrecto de parámetros\n", 39);
		exit(EXIT_FAILURE);
	}
	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		exit(EXIT_FAILURE);
	parse_map(mlx, argv[1]);
	mlx = init_gui(mlx);
	set_event_hooks(mlx);
	draw_image(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

int	terminate(void *data)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) data;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free(mlx->map_data.map);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(EXIT_SUCCESS);
}
