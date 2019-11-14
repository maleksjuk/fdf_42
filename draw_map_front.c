/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:07:47 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 15:23:22 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dx;
	int	dy;
	int	e;
	int	sign_x;
	int	sign_y;
	int	e2;

	dx = abs(point2.x - point1.x);
	dy = abs(point2.y - point1.y);
	sign_x = 1;
	if (point1.x >= point2.x)
		sign_x = -1;
	sign_y = 1;
	if (point1.y >= point2.y)
		sign_y = -1;
	e = dx - dy;
	while (point1.x != point2.x || point1.y != point2.y)
	{
		draw_pixel(param, point1.x, point1.y, first_point, get_color(point1, point2));
		e2 = 2 * e;
		if (e2 > -dy)
		{
			e -= dy;
			point1.x += sign_x;
		}
		if (e2 < dx)
		{
			e += dx;
			point1.y += sign_y;
		}
	}
}

void	draw_map(t_param *param, t_map *map)
{
	int			i;
	int			j;
	t_vector	point1;
	t_vector	point2;
	t_vector	first_point;
	t_vector	scale;

	scale = get_scale(*(param->map));
	first_point.x = WINDOW_SIZE_W / 4 - map->len_x / 2 * scale.x;
	first_point.y = WINDOW_SIZE_H / 4 - map->len_y / 2 * scale.y;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = i * scale.x;
			point1.y = j * scale.y;
			point1.z = map->elems[j][i].z;
			if (i < map->len_x - 1)
			{
				point2.x = (i + 1) * scale.x;
				point2.y = j * scale.y;
				point2.z = map->elems[j][i + 1].z;
				draw_line(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = i * scale.x;
				point2.y = (j + 1) * scale.y;
				point2.z = map->elems[j + 1][i].z;
				draw_line(param, point1, point2, &first_point);
			}
			i++;
		}
		j++;
	}
}
