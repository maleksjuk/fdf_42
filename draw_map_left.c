/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:08:47 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/12 23:20:40 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_left(t_param *param, t_vector point1, t_vector point2, t_vector *first_point, int alt)
{
	int	dy;
	int	dz;
	int	e;
	int	i;
	int	j;

	dy = point2.y - point1.y;
	dz = point2.z - point1.z;
	e = dz - dy;
	i = point1.y;
	j = point1.z;
	while (i <= point2.z - 1)
	{
		draw_pixel(param, i, j, first_point, alt);
		if (e >= 0)
		{
			j++;
			e -= dy;
		}
		i++;
		e += dz;
	}
}

void	draw_line_left_vert(t_param *param, t_vector point1, t_vector point2, t_vector *first_point, int alt)
{
	int	dy;
	int	dz;
	int	i;
	int	j;

	dy = point2.y - point1.y;
	dz = point2.z - point1.z;
	i = point1.y;
	j = point1.z;
	while (j <= point2.y - 1)
	{
		draw_pixel(param, i, j, first_point, alt);
		j++;
	}
}

void	draw_map_left(t_param *param, t_map *map)
{
	int			i;
	int			j;
	t_vector	point1;
	t_vector	point2;
	t_vector	first_point;

	first_point.x = WINDOW_SIZE_W / 4 * 3 - map->len_x / 2 * SIZE;
	first_point.y = WINDOW_SIZE_H / 4 - map->len_y / 2 * SIZE;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = i * SIZE;
			point1.y = j * SIZE;
			point1.z = map->elems[j][i] * SIZE_H;
			if (i < map->len_x - 1)
			{
				point2.x = (i + 1) * SIZE;
				point2.y = j * SIZE;
				point2.z = map->elems[j][i + 1] * SIZE_H;
				draw_line_left(param, point1, point2, &first_point, map->elems[j][i]);
			}
			if (j < map->len_y - 1)
			{
				point2.x = i * SIZE;
				point2.y = (j + 1) * SIZE;
				point2.z = map->elems[j + 1][i] * SIZE_H;
				draw_line_left_vert(param, point1, point2, &first_point, map->elems[j][i]);
			}
			i++;
		}
		j++;
	}
}
