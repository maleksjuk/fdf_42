/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:35:53 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 23:46:53 by obanshee         ###   ########.fr       */
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
# define SIZE_H 12

# define WINDOW_SIZE_H 1200
# define WINDOW_SIZE_W 2200

# define KEY_ESC 53

# define WIDTH 900
# define HEIGHT 500
# define ALTITUDE 300

typedef struct	s_vector
{
	int	x;
	int	y;
	int	z;
}				t_vector;

typedef struct	s_map
{
	t_vector	**elems;
	int			len_x;
	int			len_y;
	int			max_z;
}				t_map;

typedef struct	s_param
{
	void		*mlx;
	void		*wnd;
	void		*img;
	t_map		*map;
	t_vector	first;
	t_vector	scale;
}				t_param;

int				reader(char *file, t_map *map);
t_vector		*to_elems(char *line, int axis_y);
int				map_line(char *map, t_map *point);
int				len_nbr_line(char *line);
int				extra_char(char *line);
void			error_malloc(t_map *map);
void			error_open(t_map *map);
void			error_valid(t_map *map, char *line);
void			error_arg(void);
void			free_map(t_map *map);
t_vector		get_scale(t_map map);
int				get_color(t_vector point1, t_vector point2);
void			draw_pixel(t_param *param, t_vector coord, t_vector *first,
							int alt);
void			draw(t_param *param, t_map *map);
void			draw_map(t_param *param, t_map *map);
void			draw_map_up(t_param *param, t_map *map);
void			draw_map_iso(t_param *param, t_map *map);
int				key_hook(int keycode, t_param *param);
int				get_nbr(char *str);
void			find_max_z(t_map *map);

#endif
