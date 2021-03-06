/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 19:38:40 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 14:49:24 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color(char *color, t_pixel *pixel)
{
	size_t	l;

	l = ft_strlen(color);
	if (l == 2 || l == 4 || l == 6)
		pixel->color = ft_atoi_base(color, 16);
	else if (l == 0)
		pixel->color = 16777215;
	else
	{
		write(2, "\nWrong color\n", 13);
		exit(2);
	}
}
