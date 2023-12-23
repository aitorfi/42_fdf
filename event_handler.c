/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afidalgo <afidalgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:17:48 by afidalgo          #+#    #+#             */
/*   Updated: 2023/12/17 14:45:01 by afidalgo         ###   ########.fr       */
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
	if (key == KEY_ESC)
		terminate(mlx);
	return (0);
}
