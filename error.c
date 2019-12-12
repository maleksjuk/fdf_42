/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:48:05 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 22:26:09 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_malloc(t_map *map)
{
	ft_putstr_fd("malloc error\n", 2);
	free_map(map);
	exit(1);
}

void	error_open(t_map *map)
{
	ft_putstr_fd("error of open file\n", 2);
	free_map(map);
	exit(1);
}

void	error_valid(t_map *map, char *line)
{
	ft_putstr_fd("map invalid\n", 2);
	free(map);
	free(line);
	exit(1);
}

void	error_arg(void)
{
	ft_putstr_fd("usage: ./fdf [file]\n", 2);
	exit(1);
}

void	free_map(t_map *map)
{
	int	j;

	if (map == NULL)
		return ;
	if (map->elems)
	{
		j = 0;
		while (map->elems[j])
		{
			free(map->elems[j]);
			j++;
		}
		free(map->elems);
	}
	free(map);
}
