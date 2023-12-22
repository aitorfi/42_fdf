/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorfi <aitorfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:17:48 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/22 17:09:27 by aitorfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	handle_key_events(int key, t_mlx *mlx);

void	set_event_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->win_ptr, &handle_key_events, mlx);
	mlx_hook(mlx->win_ptr, 17, (1L << 19), &terminate, mlx);
}

static int	handle_key_events(int key, t_mlx *mlx)
{
	if (key == KEY_ESC || key == 0xFF1B)
		terminate(mlx);
	return (0);
}
