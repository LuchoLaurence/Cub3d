/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:07:24 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/21 15:03:15 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	ft_close_window(t_all *a)
{
	mlx_destroy_window(a->mlxdatas.mlx, a->mlxdatas.win);
	exit (1);
}

int	close_window(void *param)
{
	(void) param;
	exit (1);
	return (0);
}

int	ft_key_pressed(int key, t_all *a)
{
	if (key == ESC)
		ft_close_window(a);
	if (key == FORWARD)
		ft_forward(a);
	if (key == BACK)
		ft_backward(a);
	if (key == LEFT)
		ft_move_left(a);
	if (key == RIGHT)
		ft_move_right(a);
	if (key == ROTATE_LEFT)
		ft_rotate_left(a);
	if (key == ROTATE_RIGHT)
		ft_rotate_right(a);
	init_raytracing(a);
	return (0);
}
