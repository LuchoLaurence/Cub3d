/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:13:21 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/27 11:53:42 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	print_c_and_f(t_all *a, int x)
{
	int		y;
	t_map	m;

	m = a->map;
	y = 0;
	while (y < a->c.drawstart)
	{
		my_mlx_pixel_put(a, x, y, create_trgb(0, m.ceiling_red,
				m.ceiling_green, m.ceiling_blue));
		y++;
	}
	y = a->c.drawend;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(a, x, y, create_trgb(0, m.floor_red,
				m.floor_green, m.floor_blue));
		y++;
	}
	return ;
}

void	mlx_begin(t_all *a)
{
	a->mlxdatas.mlx = mlx_init();
	a->mlxdatas.win = mlx_new_window(a->mlxdatas.mlx, WIDTH,
			HEIGHT, "Cub3d");
	a->mlxdatas.img = mlx_new_image(a->mlxdatas.mlx, WIDTH, HEIGHT);
	a->mlxdatas.addr = mlx_get_data_addr(a->mlxdatas.img,
			&a->mlxdatas.bits_per_pixel, &a->mlxdatas.line_length,
			&a->mlxdatas.endian);
	return ;
}

//init pos player,dir and plane
void	init_player(t_all *a)
{
	a->c.pos_x = a->map.player_y + 0.5;
	a->c.pos_y = a->map.player_x + 0.5;
	if (a->c.orientation == 'W')
		init_direction_w(a);
	else if (a->c.orientation == 'E')
		init_direction_e(a);
	else if (a->c.orientation == 'S')
		init_direction_s(a);
	else if (a->c.orientation == 'N')
		init_direction_n(a);
	else
	{
		printf("Erreur: orientation non reconnue!\n");
		exit(1);
	}
	a->c.perp_wall_dist = 0;
	a->c.move_speed = 0.12;
	a->c.rot_speed = 0.10;
	a->c.x = 0;
	return ;
}
