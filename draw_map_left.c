/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:08:47 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/13 17:13:10 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_left(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dy;
	int	dz;
	int	e;
	int	i;
	int	j;

	dz = point2.z - point1.z;
	dy = point2.y - point1.y;
	e = dy - dz;
	i = point1.z;
	j = point1.y;
	if (dy > 0)
		while (i <= point2.z - 1)
		{
			draw_pixel(param, i, j, first_point, point1.z);
			if (e >= 0)
			{
				j++;
				e -= dz;
			}
			i++;
			e += dy;
		}
	else
		while (i <= point2.z - 1)
		{
			draw_pixel(param, i, j, first_point, point1.z);
			if (e >= 0)
			{
				j--;
				e -= dz;
			}
			i++;
			e -= dy;
		}
}

void	draw_line_left_vert(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dy;
	int	dz;
	int	i;
	int	j;
	int	e;

	dz = point2.z - point1.z;
	dy = point2.y - point1.y;
	i = point1.z;
	j = point1.y;
	while (j <= point2.y - 1)
	{
		draw_pixel(param, i, j, first_point, point1.z);
		j++;
	}

	dz = point2.z - point1.z;
	dy = point2.y - point1.y;
	e = dy - dz;
	i = point1.z;
	j = point1.y;
	if (dy > 0)
		while (j <= point2.y - 1)
		{
			draw_pixel(param, i, j, first_point, point1.z);
			if (e >= 0)
			{
				i++;
				e -= dz;
			}
			j++;
			e += dy;
		}
	else
		while (j <= point2.z - 1)
		{
			draw_pixel(param, i, j, first_point, point1.z);
			if (e >= 0)
			{
				i++;
				e -= dz;
			}
			j--;
			e -= dy;
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
			point1.z = map->elems[j][i].z * SIZE_H;
			if (i < map->len_x - 1)
			{
				point2.x = (i + 1) * SIZE;
				point2.y = j * SIZE;
				point2.z = map->elems[j][i + 1].z * SIZE_H;
				draw_line_left(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = i * SIZE;
				point2.y = (j + 1) * SIZE;
				point2.z = map->elems[j + 1][i].z * SIZE_H;
				draw_line_left_vert(param, point1, point2, &first_point);
			}
			i++;
		}
		j++;
	}
}
