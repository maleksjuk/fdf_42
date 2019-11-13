/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:10:11 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/13 16:28:00 by obanshee         ###   ########.fr       */
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

	dx = abs(point2.x - point1.x);
	dy = abs(point2.y - point1.y);
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

	dx = abs(point2.x - point1.x);
	dy = abs(point2.y - point1.y);
	i = point1.x;
	j = point1.y;
	while (j <= point2.y - 1)
	{
		draw_pixel(param, i, j, first_point, point2.x);
		j++;
	}
}

t_map	*trans_iso_map(t_map *map)
{
	t_map	*iso_map;
	int		j;
	int		i;
	double	expr;

	iso_map = (t_map *)malloc(sizeof(t_map));
	iso_map->elems = (t_vector **)malloc(sizeof(t_vector) * map->len_y);
	j = 0;
	while (j < map->len_y)
	{
		iso_map->elems[j] = (t_vector *)malloc(sizeof(t_vector) * map->len_x);
		i = 0;
		while (i < map->len_x)
		{
		//	iso_map->elems[j][i] = (t_vector)malloc(sizeof(t_vector));
			expr = 1 / sqrt(6) * (sqrt(3) * map->elems[j][i].x - sqrt(3) * map->elems[j][i].z);
			iso_map->elems[j][i].y = (int)expr;
			expr = 1 / sqrt(6) * (map->elems[j][i].x + 2 * map->elems[j][i].y + map->elems[j][i].z);
			iso_map->elems[j][i].x = (int)expr;
			i++;
		}
		j++;
	}
	return (iso_map);
}

t_map	*trans_iso_map_2(t_map *map)
{
	t_map	*iso_map;
	int		j;
	int		i;
	double	expr;
	double	angle;

	angle = 60 * 180 / M_PI;
	iso_map = (t_map *)malloc(sizeof(t_map));
	iso_map->elems = (t_vector **)malloc(sizeof(t_vector) * map->len_y);
	j = 0;
	while (j < map->len_y)
	{
		iso_map->elems[j] = (t_vector *)malloc(sizeof(t_vector) * map->len_x);
		i = 0;
		while (i < map->len_x)
		{
		//	iso_map->elems[j][i] = (t_vector)malloc(sizeof(t_vector));
			expr = cos(angle) * cos(angle) * map->elems[j][i].x - sin(angle) * map->elems[j][i].y + cos(angle) * sin(angle) * map->elems[j][i].z;
			iso_map->elems[j][i].x = (int)expr;
			expr = cos(angle) * sin(angle) * map->elems[j][i].x + cos(angle) * map->elems[j][i].y + sin(angle) * sin(angle) * map->elems[j][i].z;
			iso_map->elems[j][i].y = (int)expr;
			expr = -sin(angle) * map->elems[j][i].x + cos(angle) * map->elems[j][i].z;
			iso_map->elems[j][i].z = (int)expr;
			i++;
		}
		j++;
	}
	return (iso_map);
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
	t_map		*iso_map;

	first_point.x = WINDOW_SIZE_W / 4 * 3 - map->len_x / 2 * SIZE + 100;
	first_point.y = WINDOW_SIZE_H / 4 * 3 - map->len_y / 2 * SIZE - 100;
	iso_map = trans_iso_map_2(map);
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = map->elems[j][i].x * SIZE;
			point1.y = map->elems[j][i].y * SIZE;
			point1.z = map->elems[j][i].z * SIZE_H;
			prev_x = point1.x;
			prev_y = point1.y;
			point1.x = (prev_x - prev_y) * cos(0.523599);
			point1.y = -point1.z + (prev_x + prev_y) * sin(0.523599);
			if (i < map->len_x - 1)
			{
				point2.x = map->elems[j][i + 1].x * SIZE;
				point2.y = map->elems[j][i + 1].y * SIZE;
				point2.z = map->elems[j][i + 1].z * SIZE_H;
				prev_x = point2.x;
				prev_y = point2.y;
				point2.x = (prev_x - prev_y) * cos(0.523599);
				point2.y = -point2.z + (prev_x + prev_y) * sin(0.523599);
				draw_line_iso(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = map->elems[j + 1][i].x * SIZE;
				point2.y = map->elems[j + 1][i].y * SIZE;
				point2.z = map->elems[j + 1][i].z * SIZE;
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