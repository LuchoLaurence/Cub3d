/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:36:50 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/21 15:11:36 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	ft_rotate_left(t_all *a)
{
	a->c.olddir_x = a->c.dir_x;
	a->c.dir_x = a->c.dir_x * cos(a->c.rot_speed)
		- a->c.dir_y * sin(a->c.rot_speed);
	a->c.dir_y = a->c.olddir_x * sin(a->c.rot_speed)
		+ a->c.dir_y * cos(a->c.rot_speed);
	a->c.oldplane_x = a->c.plane_x;
	a->c.plane_x = a->c.plane_x * cos(a->c.rot_speed)
		- a->c.plane_y * sin(a->c.rot_speed);
	a->c.plane_y = a->c.oldplane_x * sin(a->c.rot_speed)
		+ a->c.plane_y * cos(a->c.rot_speed);
}

void	ft_rotate_right(t_all *a)
{
	a->c.olddir_x = a->c.dir_x;
	a->c.dir_x = a->c.dir_x * cos(-a->c.rot_speed)
		- a->c.dir_y * sin(-a->c.rot_speed);
	a->c.dir_y = a->c.olddir_x * sin(-a->c.rot_speed)
		+ a->c.dir_y * cos(-a->c.rot_speed);
	a->c.oldplane_x = a->c.plane_x;
	a->c.plane_x = a->c.plane_x * cos(-a->c.rot_speed)
		- a->c.plane_y * sin(-a->c.rot_speed);
	a->c.plane_y = a->c.oldplane_x * sin(-a->c.rot_speed)
		+ a->c.plane_y * cos(-a->c.rot_speed);
}
