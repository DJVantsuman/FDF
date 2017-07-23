/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3dmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:32:49 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 14:24:54 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	arund_z(t_pixel ***p_map, char **map, double x2, double y2)
{
	int y;
	int x;
	int lx;
	int ly;

	lx = leght_map(map, 'x');
	ly = leght_map(map, 'y');
	y = 0;
	while (y < ly)
	{
		x = 0;
		while (x < lx)
		{
			x2 = p_map[y][x]->x1 * cos((AZ * 3.14) / 180) -
				p_map[y][x]->y1 * sin((AZ * 3.14) / 180);
			y2 = p_map[y][x]->x1 * sin((AZ * 3.14) / 180) +
				p_map[y][x]->y1 * cos((AZ * 3.14) / 180);
			p_map[y][x]->x1 = x2;
			p_map[y][x]->y1 = y2;
			x++;
		}
		y++;
	}
}

void	arund_y(t_pixel ***p_map, char **map, double x2, double z2)
{
	int y;
	int x;
	int lx;
	int ly;

	lx = leght_map(map, 'x');
	ly = leght_map(map, 'y');
	y = 0;
	while (y < ly)
	{
		x = 0;
		while (x < lx)
		{
			x2 = p_map[y][x]->x1 * cos((AY * 3.14) / 180) +
				p_map[y][x]->z1 * sin((AY * 3.14) / 180);
			z2 = p_map[y][x]->x1 * sin((AY * 3.14) / 180) +
				p_map[y][x]->z1 * cos((AY * 3.14) / 180);
			p_map[y][x]->x1 = x2;
			p_map[y][x]->z1 = z2;
			x++;
		}
		y++;
	}
}

void	create_3dmap(t_pixel ***p_map, char **map, int x, int y)
{
	int lx;
	int ly;

	lx = leght_map(map, 'x');
	ly = leght_map(map, 'y');
	y = 0;
	while (y < ly)
	{
		x = 0;
		while (x < lx)
		{
			p_map[y][x]->x1 = p_map[y][x]->x;
			p_map[y][x]->y1 = p_map[y][x]->y * cos((AX * 3.14) / 180) +
				p_map[y][x]->z * sin((AX * 3.14) / 180);
			p_map[y][x]->z1 = p_map[y][x]->y * sin((AX * 3.14) / 180) +
				p_map[y][x]->z * cos((AX * 3.14) / 180);
			x++;
		}
		y++;
	}
	arund_y(p_map, map, 0, 0);
	arund_z(p_map, map, 0, 0);
}
