/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:48:06 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/27 11:53:23 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	put_textures(t_all *a)
{
	a->texture.img_data[0] = (int *)mlx_get_data_addr(a->texture.img[0],
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
	a->texture.img_data[1] = (int *)mlx_get_data_addr(a->texture.img[1],
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
	a->texture.img_data[2] = (int *)mlx_get_data_addr(a->texture.img[2],
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
	a->texture.img_data[3] = (int *)mlx_get_data_addr(a->texture.img[3],
			&a->mlxdatas.bits_per_pixel,
			&a->mlxdatas.line_length, &a->mlxdatas.endian);
}

void	init_textures(t_all *a)
{
	int	tmpwidth;
	int	tmpheight;

	a->texture.img[0] = mlx_xpm_file_to_image(a->mlxdatas.mlx,
			a->map.path_no, &tmpwidth, &tmpheight);
	a->texture.img[1] = mlx_xpm_file_to_image(a->mlxdatas.mlx,
			a->map.path_so, &tmpwidth, &tmpheight);
	a->texture.img[2] = mlx_xpm_file_to_image(a->mlxdatas.mlx,
			a->map.path_ea, &tmpwidth, &tmpheight);
	a->texture.img[3] = mlx_xpm_file_to_image(a->mlxdatas.mlx,
			a->map.path_we, &tmpwidth, &tmpheight);
	if (!a->texture.img[0] || !a->texture.img[1]
		|| !a->texture.img[2] || !a->texture.img[3])
	{
		printf("erreur la texture est inexistante");
		exit(0);
	}
	put_textures(a);
}
