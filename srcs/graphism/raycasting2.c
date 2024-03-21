/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:22:02 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/21 15:49:10 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

//Calculate distance projected on camera direction
//Calculate height of line to draw on screen
//calculate lowest and highest pixel to fill in current stripe
void	dist_projected(t_all *a)
{
	if (a->c.side == 0)
		a->c.perp_wall_dist = (a->c.sidedist_x - a->c.deltadist_x);
	else
		a->c.perp_wall_dist = (a->c.sidedist_y - a->c.deltadist_y);
	a->c.line_height = (int)(HEIGHT / a->c.perp_wall_dist);
	a->c.drawstart = -(a->c.line_height) / 2 + HEIGHT / 2;
	if (a->c.drawstart < 0)
		a->c.drawstart = 0;
	a->c.drawend = a->c.line_height / 2 + HEIGHT / 2;
	if (a->c.drawend >= HEIGHT)
		a->c.drawend = HEIGHT - 1;
}

void	print_textures(t_all *a)
{
	if (a->map.map[(int)a->c.map_x][(int)a->c.map_y] == '1')
		a->texture.color = create_trgb(0, 255, 0, 0);
	else
		a->texture.color = -1;
	if (a->c.side == 1)
		a->texture.color = a->texture.color / 2;
	if (a->texture.color != 1)
		ft_verline(a, a->c.x, a->texture.color);
}

//draw the pirxels of the stripe as a vertical line
void	ft_verline(t_all *a, int x, int color)
{
	int	temp;
	int	y1;
	int	y2;

	y1 = a->c.drawstart;
	y2 = a->c.drawend;
	if (y2 < y1)
	{
		temp = y2;
		y2 = y1;
		y1 = temp;
	}
	if (y2 < 0 || y1 >= HEIGHT || x < 0 || x >= WIDTH)
		return ;
	if (y1 < 0)
		y1 = 0;
	if (y2 >= HEIGHT)
		y2 = HEIGHT - 1;
	while (y1 <= y2)
	{
		my_mlx_pixel_put(a, x, y1, color);
		y1++;
	}
	return ;
}