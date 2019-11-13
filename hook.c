/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:49:12 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/13 19:43:39 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(param->mlx, param->wnd);
		exit(0);
	}
	return (0);
}