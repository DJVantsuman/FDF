/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 00:40:50 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 14:22:23 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_m(char *s, int j, char *n2)
{
	int	i;

	i = 1;
	while (i < 11)
	{
		if (s[i] > n2[j])
			error("\nERROR. Wrong value for z.\n");
		else if (s[i] == n2[j])
		{
			i++;
			j++;
		}
		else if (s[i] < n2[j])
			break ;
	}
}

void	check_p(char *s, int j, char *n1, int i)
{
	if (s[i] == '+')
		i++;
	if (i == 0)
		while (i < 10)
		{
			if (s[i] > n1[i])
				error("\nERROR. Wrong value for z.\n");
			else if (s[i] == n1[i])
				i++;
			else if (s[i] < n1[i])
				break ;
		}
	else
		while (i < 11)
		{
			if (s[i] > n1[j])
				error("\nERROR. Wrong value for z.\n");
			else if (s[i] == n1[j])
			{
				i++;
				j++;
			}
			else if (s[i] < n1[j])
				break ;
		}
}

void	check_z(char *s, t_pixel *pixel)
{
	int		i;
	char	*n1;
	char	*n2;

	i = 0;
	n1 = "2147483647";
	n2 = "2147483648";
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if ((i > 10 && ft_isdigit(s[0])) || (i > 11 && s[0] == '-'))
		error("\nERROR. Wrong value for z.\n");
	if (i == 10 || (i == 11 && s[0] == '+'))
	{
		check_p(s, 0, n1, 0);
		pixel->z = -LY;
	}
	else if (i == 11 && s[0] == '-')
	{
		check_m(s, 0, n2);
		pixel->z = -LY;
	}
	else
		pixel->z = -ft_atoi(s);
}
