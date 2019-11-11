/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:05:32 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/11 23:03:10 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_param *param, point1, point2)
{
	int	x;
	int	y;
	int	e;
	int	i;
	int	j;

	if (not point 1 and 2 on window)
		return ;
}

void	draw_map(t_param *param, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			if (i < map->len_x)
				draw_line();
			if (j < map->len_y)
				draw_line();
			i++;
		}
		j++;
	}
}

void	draw_reload(t_param *param)
{
	param->img = mlx_new_image(param->mlx, WINDOW_SIZE_W + 100, WINDOW_SIZE_H + 100);
	param->pixel_img = mlx_get_data_addr(param->img, &(param->bpp), &(param->s_line), &(param->ed));
	draw_map(param);
	mlx_put_image_to_window(param->mlx, param->wnd, param->img, -50, -50);
	mlx_destroy_image(param->mlx, param->img);
}