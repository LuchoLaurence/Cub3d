/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabperei <fabperei@student.42nice.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:43:37 by fabperei          #+#    #+#             */
/*   Updated: 2023/11/03 12:21:26 by fabperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

void	set_texture_path(char **dest, char *src, t_all *a)
{
	char	*str;
	char	*temp;

	str = ft_substr(src, 0, ft_strchr_xpm(src));
	a->map.path_nb++;
	if (!ft_strncmp(src, "./", 2))
	{
		if (*dest)
			free(*dest);
		*dest = str;
		return ;
	}
	temp = ft_strjoin("./", str);
	if (*dest)
		free(*dest);
	*dest = temp;
	free(str);
}

void	add_path_direction(char *line, t_all *a)
{
	int	i;

	i = 0;
	add_path_direction2(line, a);
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i])
	{
		if (!ft_strncmp(&line[i], "NO", 2))
		{
			i += 2;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			set_texture_path(&a->map.path_no, &line[i], a);
		}
		else if (!ft_strncmp(&line[i], "SO", 2))
		{
			i += 2;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			set_texture_path(&a->map.path_so, &line[i], a);
		}
		i++;
	}
}

void	add_path_direction2(char *line, t_all *a)
{
	int	i;

	i = 0;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i])
	{
		if (!ft_strncmp(&line[i], "WE", 2))
		{
			i += 2;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			set_texture_path(&a->map.path_we, &line[i], a);
		}
		else if (!ft_strncmp(&line[i], "EA", 2))
		{
			i += 2;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			set_texture_path(&a->map.path_ea, &line[i], a);
		}
		i++;
	}
}

void	free_map(t_all *a)
{
	int	i;

	i = 0;
	if (a->map.map && a->map.map[i])
	{
		while (a->map.map[i])
		{
			free(a->map.map[i]);
			i++;
		}
	}
	if (a->map.path_no)
	{
		free(a->map.path_no);
		a->map.path_no = NULL;
	}
	if (a->map.path_so)
	{
		free(a->map.path_so);
		a->map.path_so = NULL;
	}
	free_map2(a);
}

void	free_map2(t_all *a)
{
	if (a->map.path_we)
	{
		free(a->map.path_we);
		a->map.path_we = NULL;
	}
	if (a->map.path_ea)
	{
		free(a->map.path_ea);
		a->map.path_ea = NULL;
	}
	if (a->map.map)
	{
		free(a->map.map);
		a->map.map = NULL;
	}
	init_map_data(a);
}
