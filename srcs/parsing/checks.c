/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:30:31 by fabperei          #+#    #+#             */
/*   Updated: 2023/11/03 11:52:52 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cube.h"

int	check(int argc, char **argv, t_all *a)
{
	if (check2(argc, argv))
		return (1);
	init_map_data(a);
	index_first_line(argv, a);
	a->map.mapheight = map_height(argv, a);
	open_and_add_data(argv, a);
	if (check3(a))
		return (1);
	check4(a);
	return (0);
}

void	open_and_add_data(char **argv, t_all *a)
{
	int		fd;
	char	*line;

	line = "";
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		exit(EXIT_FAILURE);
	while (line)
	{
		line = get_next_line(fd);
		if (line && ft_strlen(line) > 1 && ft_line_empty(line))
		{
			add_color(line, a);
			add_path_direction(line, a);
			if (a->map.line_nb >= 6)
				add_map(line, a);
			a->map.line_nb++;
		}
		free(line);
	}
	free(line);
}

int	ft_line_empty(char *line)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = 0;
	while (line[i] && (line[i] == '\t' || line[i] == ' ' || line[i] == '\n'))
		i++;
	if (len == i)
		return (0);
	return (1);
}

void	check4(t_all *a)
{
	int	i;

	i = -1;
	while (a->map.map[++i])
	{
		if (i == 0 || !a->map.map[i + 1])
			check_1_first_line(a->map.map[i]);
	}
}

void	index_first_line(char **argv, t_all *a)
{
	t_index_vars	vars;

	vars = init_index_vars(argv);
	while (vars.line)
	{
		if (vars.line)
			free(vars.line);
		vars.line = get_next_line(vars.fd3);
		if (line_is_map(vars.line))
			vars.index = vars.i;
		if (vars.index)
		{
			a->map.index_start = vars.index;
			while (line_is_map2(vars.line))
			{
				if (vars.line)
					free(vars.line);
				vars.line = get_next_line(vars.fd3);
				vars.i++;
			}
			a->map.index_end = vars.i;
			return (free(vars.line));
		}
		vars.i++;
	}
}
