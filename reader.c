/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:56:27 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 22:28:28 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			len_nbr_line(char *line)
{
	int	len;

	len = 1;
	while (*(line + 1))
	{
		if (*line == ' ' && *(line + 1) != ' ')
			len++;
		line++;
	}
	return (len + 1);
}

int			map_line(char *map, t_map *point)
{
	int		fd;
	int		nbr;
	char	buf;

	fd = 0;
	nbr = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		error_open(point);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			nbr++;
	}
	close(fd);
	return (nbr);
}

t_vector	*to_elems(char *line, int axis_y)
{
	int			i;
	char		**array_line;
	t_vector	*a_elem;

	array_line = ft_strsplit(line, ' ');
	i = 0;
	if (!(a_elem = (t_vector *)malloc(sizeof(t_vector) * len_nbr_line(line))))
		return (NULL);
	while (array_line[i])
	{
		a_elem[i].x = i;
		a_elem[i].y = axis_y;
		a_elem[i].z = get_nbr(array_line[i]);
		i++;
	}
	free(array_line);
	return (a_elem);
}

int			reader_help(char *line, t_map *map, int *help)
{
	if (extra_char(line))
		error_valid(map, line);
	if (!(*help))
	{
		map->len_x = len_nbr_line(line) - 1;
		*help = 1;
	}
	else if (map->len_x != len_nbr_line(line) - 1)
		error_valid(map, line);
	free(line);
	return (0);
}

int			reader(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		axis_y;
	int		help;

	axis_y = 0;
	help = 0;
	if (!(map->elems = (t_vector **)malloc(sizeof(t_vector) *
		map_line(file, map))))
		error_malloc(map);
	map->len_x = 0;
	map->len_y = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		error_open(map);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(map->elems[axis_y] = (t_vector *)to_elems(line, axis_y)))
			error_malloc(map);
		reader_help(line, map, &help);
		axis_y++;
	}
	close(fd);
	map->len_y = axis_y;
	find_max_z(map);
	return (0);
}
