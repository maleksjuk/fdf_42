/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:07:47 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 23:23:41 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	tabs(int *tab, t_vector p1, t_vector p2)
{
	tab[4] = 1;
	if (p1.x >= p2.x)
		tab[4] = -1;
	tab[5] = 1;
	if (p1.y >= p2.y)
		tab[5] = -1;
}

void		draw_line(t_param *param, t_vector p1, t_vector p2, t_vector *first)
{
	int			tab[6];
	t_vector	coord;

	tab[0] = abs(p2.x - p1.x);
	tab[1] = abs(p2.y - p1.y);
	tabs(tab, p1, p2);
	tab[2] = tab[0] - tab[1];
	while (p1.x != p2.x || p1.y != p2.y)
	{
		coord.x = p1.x;
		coord.y = p1.y;
		draw_pixel(param, coord, first, get_color(p1, p2));
		tab[3] = 2 * tab[2];
		if (tab[3] > -tab[1])
		{
			tab[2] -= tab[1];
			p1.x += tab[4];
		}
		if (tab[3] < tab[0])
		{
			tab[2] += tab[0];
			p1.y += tab[5];
		}
	}
}

static void	if_1(int *count, t_param *param, t_vector point1, t_vector scale)
{
	t_vector	point2;

	if (count[0] < param->map->len_x - 1)
	{
		point2.x = (count[0] + 1) * scale.x;
		point2.y = count[1] * scale.y;
		point2.z = param->map->elems[count[1]][count[0] + 1].z;
		draw_line(param, point1, point2, &(param)->first);
	}
}

static void	if_2(int *count, t_param *param, t_vector point1, t_vector scale)
{
	t_vector	point2;

	if (count[1] < param->map->len_y - 1)
	{
		point2.x = count[0] * scale.x;
		point2.y = (count[1] + 1) * scale.y;
		point2.z = param->map->elems[count[1] + 1][count[0]].z;
		draw_line(param, point1, point2, &(param)->first);
	}
}

void		draw_map(t_param *param, t_map *map)
{
	int			count[2];
	t_vector	point1;
	t_vector	scale;

	scale = get_scale(*(param->map));
	param->first.x = WINDOW_SIZE_W / 4 - map->len_x / 2 * scale.x;
	param->first.y = WINDOW_SIZE_H / 4 - map->len_y / 2 * scale.y;
	count[1] = 0;
	while (count[1] < map->len_y)
	{
		count[0] = 0;
		while (count[0] < map->len_x)
		{
			point1.x = count[0] * scale.x;
			point1.y = count[1] * scale.y;
			point1.z = map->elems[count[1]][count[0]].z;
			if_1(count, param, point1, scale);
			if_2(count, param, point1, scale);
			count[0]++;
		}
		count[1]++;
	}
}
