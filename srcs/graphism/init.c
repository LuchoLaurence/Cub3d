/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:13:21 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/20 13:19:00 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	print_c_and_f(t_all *a)
{
	int		x;
	int		y;
	t_map	m;

	m = a->map;
	y = -1;
	while (++y < (HEIGHT / 2))
	{
		x = -1;
		while (++x < WIDTH + 1)
			my_mlx_pixel_put(a, x, y, create_trgb(0, m.ceiling_red,
					m.ceiling_green, m.ceiling_blue));
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(a, x, y, create_trgb(0, m.floor_red,
					m.floor_green, m.floor_blue));
			x++;
		}
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
