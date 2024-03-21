/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:55:54 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/21 15:59:07 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	ft_forward(t_all *a)
{
	if (a->map.map[(int)(a->c.pos_x + a->c.dir_x * a->c.move_speed)]
		[(int)a->c.pos_y] == '0')
		a->c.pos_x += a->c.dir_x * a->c.move_speed;
	if (a->map.map[(int)a->c.pos_x][(int)(a->c.pos_y + a->c.dir_y
		* a->c.move_speed)] == '0')
		a->c.pos_y += a->c.dir_y * a->c.move_speed;
}

void	ft_backward(t_all *a)
{
	if (a->map.map[(int)(a->c.pos_x - a->c.dir_x * a->c.move_speed)]
		[(int)a->c.pos_y] == '0')
		a->c.pos_x -= a->c.dir_x * a->c.move_speed;
	if (a->map.map[(int)a->c.pos_x][(int)(a->c.pos_y - a->c.dir_y
		* a->c.move_speed)] == '0')
		a->c.pos_y -= a->c.dir_y * a->c.move_speed;
}

void	ft_move_left(t_all *a)
{
	if (a->map.map[(int)(a->c.pos_x - a->c.dir_y
			* (a->c.move_speed * 2))][(int)a->c.pos_y] == '0')
		a->c.pos_x -= a->c.dir_y * a->c.move_speed;
	if (a->map.map[(int)a->c.pos_x][(int)(a->c.pos_y + a->c.dir_x
		* (a->c.move_speed * 2))] == '0')
		a->c.pos_y += a->c.dir_x * a->c.move_speed;
	return ;
}

void	ft_move_right(t_all *a)
{
	if (a->map.map[(int)(a->c.pos_x + a->c.dir_y
			* (a->c.move_speed * 2))][(int)a->c.pos_y] == '0')
		a->c.pos_x += a->c.dir_y * a->c.move_speed;
	if (a->map.map[(int)a->c.pos_x][(int)(a->c.pos_y - a->c.dir_x
		* (a->c.move_speed * 2))] == '0')
		a->c.pos_y -= a->c.dir_x * a->c.move_speed;
	return ;
}
