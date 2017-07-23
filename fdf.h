/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 14:48:06 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LX	800
# define LY	850
# define T	100
# define Z	4
# define AX	35
# define AY	-5
# define AZ	-2

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_pixel
{
	double		x;
	double		y;
	double		z;
	double		x1;
	double		y1;
	double		z1;
	int			color;
}				t_pixel;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_win;

int				get_next_line(const int fd, char **line);
int				leght_map(char **map, char f);
int				exit_x(void *par);

void			get_color(char *color, t_pixel *pixel);
void			create_image(t_pixel **pixel, char **map);
void			revers_coordinate(t_pixel ***p_map, int lx, int ly);
void			create_3dmap(t_pixel ***p_map, char **map, int x, int y);
void			write_line(t_pixel *start, t_pixel *end, t_win wind);
void			check_pixel(char *s);
void			check_z(char *s, t_pixel *pixel);
void			error(char *e);
void			my_hook(t_win wind);
#endif
