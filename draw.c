/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:05:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 16:49:49 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_color(t_vector point1, t_vector point2)
{
	int	alt;

	alt = 0;
	if (point1.z > 0 && point2.z > 0)
		alt = point1.z;
	point1.x = point1.x;
	return (alt);
}

t_vector	get_scale(t_map map)
{
	t_vector	scale;

	scale.x = WIDTH / map.len_x;
	scale.y = HEIGHT / map.len_y;
	scale.z = ALTITUDE / map.max_z;
	return (scale);
}

void		draw_pixel(t_param *param, t_vector coord, t_vector *first, int alt)
{
	int			color;
	t_vector	scale;

	scale = get_scale(*(param->map));
	color = 0xffffff;
	if (alt == param->map->max_z * scale.z || alt == param->map->max_z)
		color = 0x00ff00;
	else if (alt > 0)
		color = 0xff0000;
	mlx_pixel_put(param->mlx, param->wnd, coord.x + first->x,
		coord.y + first->y, color);
}

void		draw(t_param *param, t_map *map)
{
	draw_map(param, map);
	draw_map_up(param, map);
	mlx_string_put(param->mlx, param->wnd, WINDOW_SIZE_W / 2,
		WINDOW_SIZE_H / 10, 0xffffff, "DEMO VERSION! Here will a 'vid sboku'");
	draw_map_iso(param, map);
}
