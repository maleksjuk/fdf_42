/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:10:11 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 13:26:22 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_iso(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
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
		draw_pixel(param, point1.x, point1.y, first_point, point2.z);
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

void	draw_map_iso(t_param *param, t_map *map)
{
	int			i;
	int			j;
	t_vector	point1;
	t_vector	point2;
	t_vector	first_point;
	int			prev_x;
	int			prev_y;
	t_vector	scale;

	scale = get_scale(*(param->map));
	first_point.x = WINDOW_SIZE_W / 4 * 3 - map->len_x / 5 * scale.x;
	first_point.y = WINDOW_SIZE_H / 4 * 3 - map->len_y / 2 * scale.y;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = map->elems[j][i].x * scale.x;
			point1.y = map->elems[j][i].y * scale.y;
			point1.z = map->elems[j][i].z * scale.z;
			prev_x = point1.x;
			prev_y = point1.y;
			point1.x = (prev_x - prev_y) * cos(0.523599);
			point1.y = -point1.z + (prev_x + prev_y) * sin(0.523599);
			if (i < map->len_x - 1)
			{
				point2.x = map->elems[j][i + 1].x * scale.x;
				point2.y = map->elems[j][i + 1].y * scale.y;
				point2.z = map->elems[j][i + 1].z * scale.z;
				prev_x = point2.x;
				prev_y = point2.y;
				point2.x = (prev_x - prev_y) * cos(0.523599);
				point2.y = -point2.z + (prev_x + prev_y) * sin(0.523599);
				draw_line_iso(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = map->elems[j + 1][i].x * scale.x;
				point2.y = map->elems[j + 1][i].y * scale.y;
				point2.z = map->elems[j + 1][i].z * scale.z;
				prev_x = point2.x;
				prev_y = point2.y;
				point2.x = (prev_x - prev_y) * cos(0.523599);
				point2.y = -point2.z + (prev_x + prev_y) * sin(0.523599);
				draw_line_iso(param, point1, point2, &first_point);
			}
			i++;
		}
		j++;
	}
}