/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:05:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/12 23:21:00 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_param *param, int i, int j, t_vector *first_point, int alt)
{
	int	color;

	if (alt > 0)
		color = 0x00FF00;
	else
		color = 0xFFFFFF;
	mlx_pixel_put(param->mlx, param->wnd, i + first_point->x, j + first_point->y, color);
}

void	draw_reload(t_param *param, t_map *map)
{
//	param->img = mlx_new_image(param->mlx, WINDOW_SIZE_W + 100, WINDOW_SIZE_H + 100);
//	param->pixel_img = mlx_get_data_addr(param->img, &(param->bpp), &(param->s_line), &(param->ed));
	draw_map(param, map);
	draw_map_up(param, map);
	draw_map_left(param, map);
//	draw_map_iso(param, map);
//	mlx_put_image_to_window(param->mlx, param->wnd, param->img, -50, -50);
//	mlx_destroy_image(param->mlx, param->img);
}