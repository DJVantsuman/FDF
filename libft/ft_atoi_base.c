/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 15:01:18 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) ||
			(c >= 'a' && c <= ('a' + base - 10)));
}

int			ft_atoi_base(char *str, int base)
{
	int	rez;
	int	f;

	rez = 0;
	if (base <= 1 || base > 16)
		return (0);
	if (*str == '-')
		f = -1;
	else
		f = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (check_base(*str, base))
	{
		if ((*str > 64 && *str < 91) && *str - 'A' >= 0)
			rez = rez * base + (*str - 'A' + 10);
		else if ((*str > 96 && *str < 123) && *str - 'a' >= 0)
			rez = rez * base + (*str - 'a' + 10);
		else
			rez = rez * base + (*str - '0');
		str++;
	}
	return (rez * f);
}
