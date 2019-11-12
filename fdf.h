/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:35:53 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/12 15:21:57 by obanshee         ###   ########.fr       */
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

# define DEC_T 100
# define DEC_L 100
# define SIZE_W 20
# define SIZE_H 20
# define SIZE 30

# define WINDOW_SIZE_H 1000
# define WINDOW_SIZE_W 2000

//Move pixel
# define MOVE_UP -100
# define MOVE_DOWN 100
# define MOVE_LEFT -100
# define MOVE_RIGHT 100

# define MOVE_ZOOM_IN 1.1
# define MOVE_ZOOM_OUT 0.9

# define MOVE_ROT_X_U -M_PI / 64
# define MOVE_ROT_X_D M_PI / 64
# define MOVE_ROT_Y_U -M_PI / 64
# define MOVE_ROT_Y_D M_PI / 64
# define MOVE_ROT_Z_U -M_PI / 64
# define MOVE_ROT_Z_D M_PI / 64

// Key code
# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78

# define KEY_ROT_X_U 86
# define KEY_ROT_X_D 83
# define KEY_ROT_Y_U 87
# define KEY_ROT_Y_D 84
# define KEY_ROT_Z_U 88
# define KEY_ROT_Z_D 85

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
void	draw_map(t_param *param, t_map *map);
void	draw_reload(t_param *param, t_map *map);	// rewrite!!!

// hook.c
int		key_hook(int keycode, t_param *param);	// rewrite

// main.c
int		expose_hook(t_param *param);
void	print_map(t_map *map);

#endif
