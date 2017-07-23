/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:46:44 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 14:20:46 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *e)
{
	write(2, e, ft_strlen(e));
	exit(2);
}

int		check_symbols(char *s)
{
	int	i;

	i = 0;
	while (s[i] != ' ' && s[i] != '\0')
	{
		if (!((s[i] > 47 && s[i] < 58) || (s[i] > 64 && s[i] < 71) ||
					(s[i] > 96 && s[i] < 103) || s[i] == ',' || s[i] == 'x' ||
					s[i] == '-' || s[i] == '+'))
			error("\nERROR. Wrong symbol in the pixel coordinate.\n");
		i++;
	}
	return (1);
}

void	check_pixel(char *s)
{
	int i;

	i = 0;
	check_symbols(s);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] > 47 && s[i] < 58)
		i++;
	if (!(s[i] == ',' || s[i] == ' ' || s[i] == '\0'))
		error("\nERROR. Wrong symbol in the pixel coordinate.\n");
	if (s[i] == ',' && !(s[i + 1] == '0' && s[i + 2] == 'x'))
		error("\nERROR. Wrong color.\n");
	while (s[i] != 'x' && s[i] != ' ' && s[i] != '\0')
		i++;
	if ((s[i] == 'x' && s[i + 1] == ' '))
		error("\nERROR. Wrong color.\n");
}
