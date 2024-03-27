/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:49:03 by llaurenc       #+#    #+#             */
/*   Updated: 2024/03/25 13:34:21 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cube.h"

int	main(int argc, char **argv)
{
	t_all	a;

	if (check(argc, argv, &a))
		return (1);
	mlx_begin(&a);
	init_player(&a);
	init_textures(&a);
	init_raytracing(&a);
	mlx_hook(a.mlxdatas.win, 02, 1L << 0, &ft_key_pressed, &a);
	mlx_hook(a.mlxdatas.win, 17, 0, &(close_window), NULL);
	mlx_loop(a.mlxdatas.mlx);
}
