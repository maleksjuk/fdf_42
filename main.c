/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:33:23 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 19:25:18 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_nbr(char *str)
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

int	main(int ac, char **av)
{
	t_map	*map;
	t_param	param;

	if (ac != 2)
		return (1);
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		fdf_malloc_error();
	if (reader(av[1], map))					// ERRORS
	{
		printf("ERROR CHECK\n");
		return (0);
	}
	param.mlx = mlx_init();
	param.wnd = mlx_new_window(param.mlx, WINDOW_SIZE_W, WINDOW_SIZE_H, "FDF");
	param.map = map;
	draw(&param, map);
	mlx_hook(param.wnd, 2, 3, key_hook, &param);
	mlx_loop(param.mlx);
	return (0);
}
