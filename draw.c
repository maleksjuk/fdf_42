/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:05:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/12 19:55:24 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_param *param, int i, int j, t_vector *first_point)
{
	int	color;

	color = 0xFFFF00;
	mlx_pixel_put(param->mlx, param->wnd, i + first_point->x, j + first_point->y, color);
}

void	draw_line(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dx;
	int	dy;
	int	e;
	int	i;
	int	j;

//	if (not point 1 and 2 on window)
//		return ;
	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	e = dy - dx;
	i = point1.x;
	j = point1.y;
	while (i <= point2.x - 1)
	{
		draw_pixel(param, i, j, first_point);
		if (e >= 0)
		{
			j++;
			e -= dx;
		}
		i++;
		e += dy;
	}
}

void	draw_line_vert(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dx;
	int	dy;
//	int	e;
	int	i;
	int	j;

//	if (not point 1 and 2 on window)
//		return ;
	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	i = point1.x;
	j = point1.y;
	while (j <= point2.y - 1)
	{
		draw_pixel(param, i, j, first_point);
		j++;
	}
}

void	draw_line_up(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dx;
	int	dz;
	int	e;
	int	i;
	int	j;

//	if (not point 1 and 2 on window)
//		return ;
	dx = point2.x - point1.x;
	dz = point2.z - point1.z;
	e = dz - dx;
	i = point1.x;
	j = point1.z;
	while (i <= point2.x - 1)
	{
		draw_pixel(param, i, j, first_point);
		if (e >= 0)
		{
			j++;
			e -= dx;
		}
		i++;
		e += dz;
	}
}

void	draw_line_up_vert(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dx;
	int	dz;
//	int	e;
	int	i;
	int	j;

//	if (not point 1 and 2 on window)
//		return ;
	dx = point2.x - point1.x;
	dz = point2.z - point1.z;
	i = point1.x;
	j = point1.z;
	while (j <= point2.z - 1)
	{
		draw_pixel(param, i, j, first_point);
		j++;
	}
}

void	draw_line_left(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
{
	int	dy;
	int	dz;
	int	e;
	int	i;
	int	j;

//	if (not point 1 and 2 on window)
//		return ;
	dy = point2.y - point1.y;
	dz = point2.z - point1.z;
	e = dz - dy;
	i = point1.y;
	j = point1.z;
	while (i <= point2.z - 1)
	{
		draw_pixel(param, i, j, first_point);
		if (e >= 0)
		{
			j++;
			e -= dy;
		}
		i++;
		e += dz;
	}
}

void	draw_line_left_vert(t_param *param, t_vector point1, t_vector point2, t_vector *first_point)
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
		draw_pixel(param, i, j, first_point);
		j++;
	}
}

void	draw_map(t_param *param, t_map *map)
{
	int			i;
	int			j;
	t_vector	point1;
	t_vector	point2;
	t_vector	first_point;

	first_point.x = WINDOW_SIZE_W / 2 - map->len_x / 2 * SIZE;
	first_point.y = WINDOW_SIZE_H / 2 - map->len_y / 2 * SIZE;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = i * SIZE;
			point1.y = j * SIZE;
			point1.z = map->elems[j][i];
			if (i < map->len_x - 1)
			{
				point2.x = (i + 1) * SIZE;
				point2.y = j * SIZE;
				point2.z = map->elems[j][i + 1];
				draw_line(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = i * SIZE;
				point2.y = (j + 1) * SIZE;
				point2.z = map->elems[j + 1][i];
				draw_line_vert(param, point1, point2, &first_point);
			}
			i++;
		}
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

	first_point.x = WINDOW_SIZE_W / 2 - map->len_x / 2 * SIZE;
	first_point.y = WINDOW_SIZE_H / 2 - map->len_y / 2 * SIZE;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = i * SIZE;
			point1.y = j * SIZE;
			point1.z = map->elems[j][i] * SIZE;
			if (i < map->len_x - 1)
			{
				point2.x = (i + 1) * SIZE;
				point2.y = j * SIZE;
				point2.z = map->elems[j][i + 1] * SIZE;
				draw_line_up(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = i * SIZE;
				point2.y = (j + 1) * SIZE;
				point2.z = map->elems[j + 1][i] * SIZE;
				draw_line_up_vert(param, point1, point2, &first_point);
			}
			i++;
		}
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

	first_point.x = WINDOW_SIZE_W / 2 - map->len_x / 2 * SIZE;
	first_point.y = WINDOW_SIZE_H / 2 - map->len_y / 2 * SIZE;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			point1.x = i * SIZE;
			point1.y = j * SIZE;
			point1.z = map->elems[j][i];
			if (i < map->len_x - 1)
			{
				point2.x = (i + 1) * SIZE;
				point2.y = j * SIZE;
				point2.z = map->elems[j][i + 1];
				draw_line_left(param, point1, point2, &first_point);
			}
			if (j < map->len_y - 1)
			{
				point2.x = i * SIZE;
				point2.y = (j + 1) * SIZE;
				point2.z = map->elems[j + 1][i];
				draw_line_left_vert(param, point1, point2, &first_point);
			}
			i++;
		}
		j++;
	}
}

void	draw_reload(t_param *param, t_map *map)
{
//	param->img = mlx_new_image(param->mlx, WINDOW_SIZE_W + 100, WINDOW_SIZE_H + 100);
//	param->pixel_img = mlx_get_data_addr(param->img, &(param->bpp), &(param->s_line), &(param->ed));
	draw_map_left(param, map);
//	mlx_put_image_to_window(param->mlx, param->wnd, param->img, -50, -50);
//	mlx_destroy_image(param->mlx, param->img);
}