/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:36:54 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 15:07:06 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	revers_coordinate(t_pixel ***p_map, int lx, int ly)
{
	int i;
	int j;
	int x;
	int y;
	int n;

	y = 0;
	j = -ly / 2;
	n = LX / lx;
	while (y < ly)
	{
		x = 0;
		i = -lx / 2;
		while (x < lx)
		{
			p_map[y][x]->x = i;
			p_map[y][x]->y = j;
			if (n > Z + 3)
				p_map[y][x]->z *= Z;
			i++;
			x++;
		}
		y++;
		j++;
	}
}
