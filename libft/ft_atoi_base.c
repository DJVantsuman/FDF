/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/05/20 16:02:33 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_inbase(char c, int base)
{
    if (base <= 10)
        return (c >= '0' && c <= '9');
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

int	ft_atoi_base(char *str, int base)
{
    int	value;
    int	f;

    value = 0;
    if (base <= 1 || base > 36)
        return (0);
    f = (*str == '-') ? -1 : 1;
    if (*str == '-' || *str == '+')
        str++;
    while (ft_inbase(*str, base))
    {
        if (*str - 'A' >= 0)
            value = value * base + (*str - 'A' + 10);
        else
            value = value * base + (*str - '0');
        str++;
    }
    return (value * f);
}