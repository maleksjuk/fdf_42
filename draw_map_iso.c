/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:10:11 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/12 23:13:48 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_iso(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dx;
	int	dy;
	int	e;
	int	i;
	int	j;

	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	e = dy - dx;
	i = point1.x;
	j = point1.y;
	while (i <= point2.x - 1)
	{
		draw_pixel(param, i, j, first_point, point2.x);
		if (e >= 0)
		{
			j++;
			e -= dx;
		}
		i++;
		e += dy;
	}
}

void	draw_line_iso_vert(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dx;
	int	dy;
	int	i;
	int	j;

	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	i = point1.x;
	j = point1.y;
	while (j <= point2.y - 1)
	{
		draw_pixel(param, i, j, first_point, point2.x);
		j++;
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

	first_point.x = WINDOW_SIZE_W / 4 * 3 - map->len_x / 2 * SIZE;
	first_point.y = WINDOW_SIZE_H / 4 * 3 - map->len_y / 2 * SIZE;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = i * SIZE;
			point1.y = j * SIZE;
			point1.z = map->elems[j][i];
			prev_x = point1.x;
			prev_y = point1.y;
			point1.x = (prev_x - prev_y) * cos(0.523599);
			point1.y = -point1.z + (prev_x + prev_y) * sin(0.523599);
			if (i < map->len_x - 1)
			{
				point2.x = (i + 1) * SIZE;
				point2.y = j * SIZE;
				point2.z = map->elems[j][i + 1] * SIZE;
				prev_x = point2.x;
				prev_y = point2.y;
				point2.x = (prev_x - prev_y) * cos(0.523599);
				point2.y = -point2.z + (prev_x + prev_y) * sin(0.523599);
				draw_line_iso(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = i * SIZE;
				point2.y = (j + 1) * SIZE;
				point2.z = map->elems[j + 1][i] * SIZE;
				prev_x = point2.x;
				prev_y = point2.y;
				point2.x = (prev_x - prev_y) * cos(0.523599);
				point2.y = -point2.z + (prev_x + prev_y) * sin(0.523599);
				draw_line_iso_vert(param, point1, point2, &first_point);
			}
			i++;
		}
		j++;
	}
}