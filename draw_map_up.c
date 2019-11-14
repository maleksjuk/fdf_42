/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:09:33 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 13:20:45 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_up(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	/*int	dx;
	int	dz;
	int	e;
	int	i;
	int	j;

	dx = point2.x - point1.x;
	dz = point2.z - point1.z;
	e = dz - dx;
	i = point1.x;
	j = point1.z;
	if (dz > 0)
		while (i <= point2.x - 1)
		{
			draw_pixel(param, i, j, first_point, point1.z);
			if (e >= 0)
			{
				j++;
				e -= dx;
			}
			i++;
			e += dz;
		}
	else
		while (i <= point2.x - 1)
		{
			draw_pixel(param, i, j, first_point, point1.z);
			if (e >= 0)
			{
				j--;
				e -= dx;
			}
			i++;
			e -= dz;
		}*/

	int	dx;
	int	dz;
	int	e;
	int	sign_x;
	int	sign_z;
	int	e2;

	dx = abs(point2.x - point1.x);
	dz = abs(point2.z - point1.z);
	sign_x = 1;
	if (point1.x >= point2.x)
		sign_x = -1;
	sign_z = 1;
	if (point1.z >= point2.z)
		sign_z = -1;
	e = dx - dz;
	while (point1.x != point2.x || point1.z != point2.z)
	{
		draw_pixel(param, point1.x, point1.z, first_point, point2.z);
		e2 = 2 * e;
		if (e2 > -dz)
		{
			e -= dz;
			point1.x += sign_x;
		}
		if (e2 < dx)
		{
			e += dx;
			point1.z += sign_z;
		}
	}	
}

void	draw_line_up_vert(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dx;
	int	dz;
	int	i;
	int	j;

	dx = point2.x - point1.x;
	dz = point2.z - point1.z;
	i = point1.x;
	j = point1.z;
	while (j <= point2.z - 1)
	{
		draw_pixel(param, i, j, first_point, point1.z);
		j++;
	}
}

void	draw_map_up(t_param *param, t_map *map)
{
	int			i;
	int			j;
	t_vector	point1;
	t_vector	point2;
	t_vector	first_point;
	t_vector	scale;

	/*scale.x = WIDTH / map->len_x;
	scale.y = HEIGHT / map->len_y;
	scale.z = ALTITUDE / map->max_z;*/
	scale = get_scale(*(param->map));
	first_point.x = WINDOW_SIZE_W / 4 - map->len_x / 2 * scale.x;
	first_point.y = WINDOW_SIZE_H / 4 * 3 - map->len_y / 2 * scale.y;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = i * scale.x; //SIZE;
			point1.y = j * scale.y; //SIZE;
			point1.z = map->elems[j][i].z * scale.z; //SIZE_H;
			if (i < map->len_x - 1)
			{
				point2.x = (i + 1) * scale.x; //SIZE;
				point2.y = j * scale.y; //SIZE;
				point2.z = map->elems[j][i + 1].z * scale.z; //SIZE_H;
				draw_line_up(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = i * scale.x; //SIZE;
				point2.y = (j + 1) * scale.y; //SIZE;
				point2.z = map->elems[j + 1][i].z * scale.z; //SIZE_H;
				draw_line_up(param, point1, point2, &first_point);
			//	draw_line_up_vert(param, point1, point2, &first_point);
			}
			i++;
		}
		j++;
	}
}
