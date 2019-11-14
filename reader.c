/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:56:27 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 19:25:04 by obanshee         ###   ########.fr       */
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

int			map_line(char *map)
{
	int		fd;
	int		nbr;
	char	buf;

	fd = 0;
	nbr = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		fdf_map_error();
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
	t_vector	*array_elem;

	array_line = ft_strsplit(line, ' ');
	i = 0;
	array_elem = (t_vector *)malloc(sizeof(t_vector) * len_nbr_line(line));
	while (array_line[i])
	{
		array_elem[i].x = i;
		array_elem[i].y = axis_y;
		array_elem[i].z = get_nbr(array_line[i]);
		i++;
	}
	return (array_elem);
}

void		find_max_z(t_map *map)
{
	int	i;
	int	j;

	map->max_z = 0;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			if (map->elems[j][i].z > map->max_z)
				map->max_z = map->elems[j][i].z;
			i++;
		}
		j++;
	}
}

int		reader(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		axis_y;
//	t_map	*map;
	int		help;

	axis_y = 0;
	help = 0;
	if (!(map->elems = (t_vector **)malloc(sizeof(t_vector) * map_line(file))))
		fdf_malloc_error();
	map->len_x = 0;
	map->len_y = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		fdf_exit();
	
	while (get_next_line(fd, &line) > 0)
	{
		if (extra_char(line))								// ERRORS
			return (1);
		map->elems[axis_y] = (t_vector *)to_elems(line, axis_y);
		if (!help)
		{
			map->len_x = len_nbr_line(line) - 1;
			help = 1;
		}
		else if (map->len_x != len_nbr_line(line) - 1)		// ERRORS
			return (1);
		axis_y++;
	}
	close(fd);
	map->len_y = axis_y;
	find_max_z(map);
	return (0);
}
