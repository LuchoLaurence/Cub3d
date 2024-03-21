/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:00:56 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/21 15:53:31 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

//init pos player,dir and plane
void	init_player(t_all *a)
{
	a->c.pos_x = 4;
	a->c.pos_y = 14;
	a->c.dir_x = -1;
	a->c.dir_y = 0;
	a->c.plane_x = 0;
	a->c.plane_y = 0.66;
	a->c.move_speed = 0.15;
	a->c.rot_speed = 0.05;
	return ;
}

void	init_raytracing(t_all *a)
{
	print_c_and_f(a);
	a->c.x = 0;
	while (a->c.x < WIDTH)
	{
		a->c.camera_x = 2 * a->c.x / (double)WIDTH - 1;
		a->c.raydir_x = a->c.dir_x + a->c.plane_x * a->c.camera_x;
		a->c.raydir_y = a->c.dir_y + a->c.plane_y * a->c.camera_x;
		a->c.map_x = (int)a->c.pos_x;
		a->c.map_y = (int)a->c.pos_y;
		dist_to_side(a);
		side_dist(a);
		dda(a);
		dist_projected(a);
		print_textures(a);
		a->c.x++;
	}
	mlx_put_image_to_window(a->mlxdatas.mlx,
		a->mlxdatas.win, a->mlxdatas.img, 0, 0);
	return ;
}

//length of ray from one x or y-side to next x or y-side
void	dist_to_side(t_all *a)
{
	if (a->c.raydir_x == 0)
		a->c.deltadist_x = 1e30;
	else
		a->c.deltadist_x = fabs(1.0 / a->c.raydir_x);
	if (a->c.raydir_y == 0)
		a->c.deltadist_y = 1e30;
	else
		a->c.deltadist_y = fabs(1.0 / a->c.raydir_y);
	a->c.hit = 0;
}

//calculate step and initial sideDist to next x wall or y wall
void	side_dist(t_all *a)
{
	if (a->c.raydir_x < 0)
	{
		a->c.step_x = -1;
		a->c.sidedist_x = (a->c.pos_x - a->c.map_x) * a->c.deltadist_x;
	}
	else
	{
		a->c.step_x = 1;
		a->c.sidedist_x = (a->c.map_x + 1.0 - a->c.pos_x) * a->c.deltadist_x;
	}
	if (a->c.raydir_y < 0)
	{
		a->c.step_y = -1;
		a->c.sidedist_y = (a->c.pos_y - a->c.map_y) * a->c.deltadist_y;
	}
	else
	{
		a->c.step_y = 1;
		a->c.sidedist_y = (a->c.map_y + 1.0 - a->c.pos_y) * a->c.deltadist_y;
	}
}

//dda
void	dda(t_all *a)
{
	while (a->c.hit == 0)
	{
		if (a->c.sidedist_x < a->c.sidedist_y)
		{
			a->c.sidedist_x += a->c.deltadist_x;
			a->c.map_x += a->c.step_x;
			a->c.side = 0;
		}
		else
		{
			a->c.sidedist_y += a->c.deltadist_y;
			a->c.map_y += a->c.step_y;
			a->c.side = 1;
		}
		if (a->map.map[(int)a->c.map_x][(int)a->c.map_y] == '1')
			a->c.hit = 1;
	}
}
