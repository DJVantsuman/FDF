/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/05/20 16:02:33 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

#define LX  800
#define LY  700
#define T   100
#define Z   3
#define AX  25
#define AY  20
#define AZ  15

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_pixel
{
    double      x;
    double      y;
    double      z;
    double      x1;
    double      y1;
    double      z1;
    int         col_R;
    int         col_G;
    int         col_B;
}               t_pixel;

typedef struct  s_win
{
    void        *mlx;
    void        *win;
    void        *img;
}               t_win;

int             get_next_line(const int fd, char **line);
int             leght_map(char **map, char f);
void             get_color(char *color, t_pixel *pixel);

void            create_image(t_pixel **pixel, char **map);
void            create_3dmap(t_pixel ***p_map, char **map);
void            write_line(t_pixel *start, t_pixel *end, t_win wind);

#endif