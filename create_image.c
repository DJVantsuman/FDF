/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/05/20 16:02:33 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     leght_map(char **map, char f)
{
    int count;
    int i;

    i = 0;
    count = 0;
    if (f == 'x')
    {
        while (map[0][i]) {
            count++;
            while (map[0][i] != ' ' && map[0][i] != '\0')
                i++;
            if (map[0][i] == '\0')
                break;
            while (map[0][i] == ' ')
                i++;
        }
    }
    else if (f == 'y')
    {
        while (map[count])
            count++;
    }
    return (count);
}

void    scalling(t_pixel ***p_map, int lx, int ly)
{
    int x;
    int y;
    int dx;
    int dy;
    int s;

    y = 0;
    dx = LX / 2;
    dy = LY / 2;
    s = LX / lx;
    if (s > 10)
        s -= 10;
    else if (s > 1)
        s -= 1;
    while (y < ly)
    {
        x = 0;
        while (x < lx)
        {
            p_map[y][x]->x = (p_map[y][x]->x * s) + dx;
            p_map[y][x]->y = (p_map[y][x]->y * s) + dy;
            x++;
        }
        y++;
    }
}

void    draw(t_pixel ***p_map, t_win wind, char **map)
{
    int i;
    int j;
    int lx;
    int ly;

    i = 0;
    lx = leght_map(map, 'x');
    ly = leght_map(map, 'y');
    while (i < ly)
    {
        j = 0;
        while (j < lx)
        {
            if (i > 0)
                write_line(p_map[i][j], p_map[i - 1][j], wind);
            if (j + 1 < lx)
                write_line(p_map[i][j], p_map[i][j + 1], wind);
            j++;
        }
        i++;
    }
}

void    create_pixel_map(t_pixel **pixel, t_pixel ***p_map, t_win wind, char **map)
{
    int i;
    int j;
    int t;
    int lx;

    i = 0;
    t = 0;
    lx = leght_map(map, 'x');
    while (pixel[t])
    {
        p_map[i] = (t_pixel **)malloc(sizeof(t_pixel*) * lx);
        j = 0;
        while (j < lx && pixel[t])
        {
            p_map[i][j] = pixel[t];
            j++;
            t++;
        }
        i++;
    }
    revers_coordinate(p_map, lx, leght_map(map, 'y'));
    scalling(p_map, lx, leght_map(map, 'y'));
    create_3dmap(p_map, map);
    draw(p_map, wind, map);
    mlx_loop(wind.mlx);
}

void    create_image(t_pixel **pixel, char **map)
{
    void    *mlx;
    void    *win;
    t_win   wind;
    t_pixel ***p_map;

    p_map = (t_pixel ***)malloc(sizeof(t_pixel**) * leght_map(map, 'y'));
    mlx = mlx_init();
    win = mlx_new_window(mlx, LX , LY, "fdf");
    wind.mlx = mlx;
    wind.win = win;
    create_pixel_map(pixel, p_map, wind, map);
}