/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/05/20 16:02:33 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    write_line_1(t_pixel *start, t_pixel *end, t_win wind, int nbr[])
{
    double x;
    double y;
    int d;
    int d1;
    int d2;

    d = (nbr[1] << 1) - nbr[0];
    d1 = nbr[1] << 1;
    d2 = (nbr[1] - nbr[0]) << 1;
    x = start->x1;
    y = start->y1;
    mlx_pixel_put(wind.mlx, wind.win, x , y, (end->col_R, end->col_G, end->col_B));
    x = start->x1 + nbr[2];
    while (nbr[4] <= nbr[0])
    {
        if ( d >0)
        {
            d += d2;
            y += nbr[3];
        }
        else
            d += d1;
        mlx_pixel_put(wind.mlx, wind.win, x , y, (end->col_R, end->col_G, end->col_B));
        nbr[4]++;
        x += nbr[2];
    }
}

void    write_line_2(t_pixel *start, t_pixel *end, t_win wind, int nbr[])
{
    double x;
    double y;
    int d;
    int d1;
    int d2;

    d = (nbr[0] << 1) - nbr[1];
    d1 = nbr[0] << 1;
    d2 = (nbr[0] - nbr[1]) << 1;
    x = start->x1;
    y = start->y1;
    mlx_pixel_put(wind.mlx, wind.win, x , y, (start->col_R, start->col_G, start->col_B));
    y = start->y1 + nbr[3];
    while (nbr[4] <= nbr[1])
    {
        if ( d >0)
        {
            d += d2;
            x += nbr[2];
        }
        else
            d += d1;
        mlx_pixel_put(wind.mlx, wind.win, x , y, (start->col_R, start->col_G, start->col_B));
        nbr[4]++;
        y += nbr[3];
    }
}

/*
** nbr[0] = dx;
** nbr[1] = dy;
** nbr[2] = sx;
** nbr[3] = sy;
** nbr[4] = i = 1;
*/

void    write_line(t_pixel *start, t_pixel *end, t_win wind)
{
    int nbr[5];

    nbr[0] = abs((int)end->x1 - (int)start->x1);
    nbr[1] = abs((int)end->y1 - (int)start->y1);
    nbr[2] = end->x1 >= start->x1 ? 1 : -1;
    nbr[3] = end->y1 >= start->y1 ? 1 : -1;
    nbr[4] = 1;

    if (nbr[1] <= nbr[0])
        write_line_1(start, end, wind, nbr);
    else
    {
        write_line_2(start, end, wind, nbr);
    }
}