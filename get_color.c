/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 19:38:40 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/13 19:38:43 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char    *get_B(char *color, size_t l)
{
    char    s[3];

    s[2] = 0;
    if (l == 6)
    {
        s[0] = color[4];
        s[1] = color[5];
    }
    else if (l == 4)
    {
        s[0] = color[2];
        s[1] = color[3];
    }
    else if (l == 2)
    {
        s[0] = color[0];
        s[1] = color[1];
    }
    else
    {
        s[0] = 'f';
        s[1] = 'f';
    }
    return (ft_strjoin("", s));
}

char    *get_G(char *color, size_t l)
{
    char    s[3];

    s[2] = 0;
    if (l == 6)
    {
        s[0] = color[2];
        s[1] = color[3];
    }
    else if (l == 4)
    {
        s[0] = color[0];
        s[1] = color[1];
    }
    else
    {
        s[0] = 'f';
        s[1] = 'f';
    }
    return (ft_strjoin("", s));
}

char    *get_R(char *color, size_t l)
{
    char    s[3];

    s[2] = 0;
    if (l == 6)
    {
        s[0] = color[0];
        s[1] = color[1];
    }
    else
    {
        s[0] = 'f';
        s[1] = 'f';
    }
    return (ft_strjoin("", s));
}

void     get_color(char *color, t_pixel *pixel)
{
    size_t  l;

    l = ft_strlen(color);
    if (l > 0)
    {
        pixel->col_R = ft_atoi_base(get_B(color, l), 16);
        pixel->col_G = ft_atoi_base(get_G(color, l), 16);
        pixel->col_B = ft_atoi_base(get_R(color, l), 16);

    }
}