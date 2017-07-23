/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:04:57 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 14:51:35 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		key_hook(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
		exit(1);
	return (0);
}

void	my_hook(t_win wind)
{
	mlx_hook(wind.win, 17, 1L << 17, exit_x, 0);
	mlx_key_hook(wind.win, key_hook, 0);
}
