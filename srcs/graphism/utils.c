/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:09:14 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/21 14:05:07 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_all *a, int x, int y, int color)
{
	char	*dst;

	dst = a->mlxdatas.addr + (y * a->mlxdatas.line_length + x
			*(a->mlxdatas.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
