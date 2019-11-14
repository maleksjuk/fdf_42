/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:05:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 12:26:57 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_param *param, int i, int j, t_vector *first_point, int alt)
{
	int	color;

	color = 0xffffff;
	if (alt == param->map->max_z)
		color = 0x00ff00;
	else if (alt > 0)
		color = 0xff0000;
	/*if (alt > 0)
		color = 0x00FF00;
	else
		color = 0xFFFFFF;*/
	mlx_pixel_put(param->mlx, param->wnd, i + first_point->x, j + first_point->y, color);
}

void	draw(t_param *param, t_map *map)
{
//	param->img = mlx_new_image(param->mlx, WINDOW_SIZE_W + 100, WINDOW_SIZE_H + 100);
	draw_map(param, map);
	draw_map_up(param, map);
//	draw_map_left(param, map);
	mlx_string_put(param->mlx, param->wnd, WINDOW_SIZE_W / 2,
		WINDOW_SIZE_H / 10, 0xffffff, "DEMONSTRATION VERSION!!! Here will a 'vid sboku'");
	draw_map_iso(param, map);
//	mlx_put_image_to_window(param->mlx, param->wnd, param->img, 50, 50);
//	mlx_destroy_image(param->mlx, param->img);
}