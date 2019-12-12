/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:33:23 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 22:28:24 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_nbr(char *str)
{
	int nbr;
	int negative;

	negative = 0;
	if (str[0] == '-')
	{
		negative = 1;
		str++;
	}
	nbr = 0;
	while ((*str >= '0') && (*str <= '9'))
		nbr = (nbr * 10) + *str++ - '0';
	return ((negative == 1) ? -nbr : nbr);
}

void	find_max_z(t_map *map)
{
	int	i;
	int	j;

	map->max_z = 0;
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			if (map->elems[j][i].z > map->max_z)
				map->max_z = map->elems[j][i].z;
			i++;
		}
		j++;
	}
}

int		key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(param->mlx, param->wnd);
		exit(0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_map	*map;
	t_param	param;

	if (ac != 2)
		error_arg();
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		error_malloc(NULL);
	reader(av[1], map);
	param.mlx = mlx_init();
	param.wnd = mlx_new_window(param.mlx, WINDOW_SIZE_W, WINDOW_SIZE_H, "FDF");
	param.map = map;
	draw(&param, map);
	mlx_hook(param.wnd, 2, 3, key_hook, &param);
	mlx_loop(param.mlx);
	return (0);
}
