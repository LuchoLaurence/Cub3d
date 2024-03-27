/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:38:23 by llaurenc          #+#    #+#             */
/*   Updated: 2024/03/25 13:38:27 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	init_direction_w(t_all *a)
{
	a->c.dir_x = 0;
	a->c.dir_y = -1;
	a->c.plane_x = -0.66;
	a->c.plane_y = 0;
}

void	init_direction_e(t_all *a)
{
	a->c.dir_x = 0;
	a->c.dir_y = 1;
	a->c.plane_x = 0.66;
	a->c.plane_y = 0;
}

void	init_direction_s(t_all *a)
{
	a->c.dir_x = 1;
	a->c.dir_y = 0;
	a->c.plane_x = 0;
	a->c.plane_y = -0.66;
}

void	init_direction_n(t_all *a)
{
	a->c.dir_x = -1;
	a->c.dir_y = 0;
	a->c.plane_x = 0;
	a->c.plane_y = 0.66;
}
