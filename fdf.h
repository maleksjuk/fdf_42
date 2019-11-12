/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:35:53 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/12 23:18:26 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "libft/includes/libft.h"

# define SIZE 30
# define SIZE_H 10

# define WINDOW_SIZE_H 800
# define WINDOW_SIZE_W 1600

// Key code
# define KEY_ESC 53

# define KEY_FRONT 89
# define KEY_UP 83
# define KEY_LEFT 92
# define KEY_ISO 85

typedef struct	s_vector
{
	int	x;
	int	y;
	int	z;
}				t_vector;

typedef struct	s_map 
{
	int	**elems;
	int	len_x;
	int	len_y;
}				t_map;

typedef struct	s_param
{
	void	*mlx;
	void	*wnd;
	void	*img;
	t_map	*map;
}				t_param;

// reader.c
t_map	*reader(char *file);
int		*to_elems(char *line);
int		ft_map_line(char *map);		// rewrite!!!
int		ft_getnbr(char *str);
int		len_nbr_line(char *line);

// error.c
void	fdf_exit(void);
void	fdf_malloc_error(void);
void	fdf_map_error(void);
void	fdf_arg_error(void);

// draw.c
void	draw_pixel(t_param *param, int i, int j, t_vector *first_point, int alt);
void	draw_reload(t_param *param, t_map *map);	// rewrite!!!

// draw_map_front.c
void	draw_map(t_param *param, t_map *map);

// draw_map_up.c
void	draw_map_up(t_param *param, t_map *map);

// draw_map_left.c
void	draw_map_left(t_param *param, t_map *map);

// draw_map_iso.c
void	draw_map_iso(t_param *param, t_map *map);

// hook.c
int		key_hook(int keycode, t_param *param);	// rewrite

// main.c
int		expose_hook(t_param *param);
void	print_map(t_map *map);

#endif
