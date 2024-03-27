/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:22:02 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/27 11:40:02 by llaurenc         ###   ########.fr       */
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

void	choose_texture(t_all *a)
{
	if (a->c.side == 0 && a->c.raydir_x < 0)
	{
		a->c.color_text = a->texture.img_data[0][TEXHEIGHT
			* a->texture.tex_y + a->texture.tex_x];
	}
	if (a->c.side == 0 && a->c.raydir_x > 0)
	{
		a->c.color_text = a->texture.img_data[1][TEXHEIGHT
			* a->texture.tex_y + a->texture.tex_x];
	}
	if (a->c.side == 1 && a->c.raydir_y < 0)
	{
		a->c.color_text = a->texture.img_data[3][TEXHEIGHT
			* a->texture.tex_y + a->texture.tex_x];
	}
	if (a->c.side == 1 && a->c.raydir_y > 0)
	{
		a->c.color_text = a->texture.img_data[2][TEXHEIGHT
			* a->texture.tex_y + a->texture.tex_x];
	}
}

void	print_textures(t_all *a)
{
	a->texture.tex_num = a->map.map[(int)a->c.map_x][(int)a->c.map_y] - 1;
	if (a->c.side == 0)
		a->texture.wall_x = a->c.pos_y + a->c.perp_wall_dist * a->c.raydir_y;
	else
		a->texture.wall_x = a->c.pos_x + a->c.perp_wall_dist * a->c.raydir_x;
	a->texture.wall_x -= floor((a->texture.wall_x));
	a->texture.tex_x = (int)(a->texture.wall_x * (double)TEXWIDTH);
	if (a->c.side == 0 && a->c.raydir_x > 0)
		a->texture.tex_x = TEXWIDTH - a->texture.tex_x - 1;
	if (a->c.side == 1 && a->c.raydir_y < 0)
		a->texture.tex_x = TEXWIDTH - a->texture.tex_x - 1;
	a->texture.step = 1.0 * TEXHEIGHT / a->c.line_height;
	a->texture.tex_pos = (a->c.drawstart - HEIGHT / 2
			+ a->c.line_height / 2) * a->texture.step;
	a->c.y = a->c.drawstart;
	while (a->c.y <= a->c.drawend)
	{
		a->texture.tex_y = (int)a->texture.tex_pos & (TEXHEIGHT - 1);
		a->texture.tex_pos += a->texture.step;
		choose_texture(a);
		if (a->c.side == 0)
			a->c.color_text = (a->c.color_text >> 1) & 8355711;
		my_mlx_pixel_put(a, a->c.x, a->c.y, a->c.color_text);
		a->c.y ++;
	}
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
