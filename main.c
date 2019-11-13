/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:33:23 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/13 19:45:10 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	print_map(t_map *map)
{
	int	i;
	int	j;

	printf("=== BEGIN ===\n");
	j = 0;
	while (j < map->len_y)
	{
		i = 0;
		while (i < map->len_x)
		{
			printf("%-*i", 3, map->elems[j][i].z);
			i++;
		}
		printf("\n");
		j++;
	}
	printf("=== END ===\n");
}*/

int		main(int ac, char **av)
{
	t_map	*map;
	t_param	param;

	printf("*** main.c: begin\n");
	if (ac != 2)
		return (1);
	map = reader(av[1]);
	param.mlx = mlx_init();
	param.wnd = mlx_new_window(param.mlx, WINDOW_SIZE_W, WINDOW_SIZE_H, "FDF");
	param.map = map;
//	print_map(map);
	draw(&param, map);
	mlx_hook(param.wnd, 2, 3, key_hook, &param);
	mlx_loop(param.mlx);
	return (0);
}
