/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/05/20 16:02:33 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_inbase(char c, int base)
{
    if (base <= 10)
        return (c >= '0' && c <= '9');
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)));
}

int	ft_atoi_base(char *str, int base)
{
    int	value;
    int	sign;

    value = 0;
    if (base <= 1 || base > 36)
        return (0);
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
           || *str == '\r' || *str == '\v')
        str++;
    sign = (*str == '-') ? -1 : 1;
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
    return (value * sign);
}

void    create_struct(t_pixel **pixel, char **map)
{

}

void    write_map(char ***map, char *file)
{
    int     fd;
    char    *line;
    char    *str;
    char    *del;

    fd = open(file, O_RDONLY);
    line = NULL;
    str = "";
    if (fd > 0)
    {
        while (get_next_line(fd, &line) > 0)
        {
            del = str;
            str = ft_strjoin(str, ft_strjoin(line, "\n"));
            if (del[0] != '\0')
              ft_strdel(&del);
            ft_strdel(&line);
        }
        *map = ft_strsplit(str, '\n');
    }
    else
    {
        write(1, "ERROR: wrong file.\n", 19);
        exit(1);
    }
}

int     main(int ac, char **av)
{
    char **map;
    t_pixel *pixel;

    map = NULL;
    pixel = 0;
    if (ac == 2)
    {
        write_map(&map, av[1]);
        create_struct(&pixel, map);
    }
    else
        write(1, "ERROR: not valid file.\n", 23);


    ////////////////////////////////
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
	return (1);
}

/*
int ft_exit(int keycode)
{
    printf("event is %d\n", keycode);
    if (keycode == 53)
        exit (0);
    return (0);
}

int     exit_buttons(void)
{
    exit(1);
    return (0);
}

int mouse_hook(int bottom, int x, int y, void *s)
{
    printf("key: %d (%d:%d)\n", bottom, x, y);
    return (0);
}


int test(void)
{
    void    *mlx;
    void    *win;
    int     x;
    int     y;
    int     n;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 600, 600, "mlx 42");
    x = 50;
    y = 50;
    n = 0;
    while (x < 150 && y < 150)
    {
        mlx_pixel_put(mlx, win, x, y, 0x00ffffff);
        x++;
        n++;
        if (n == 3)
        {
            y++;
            n = 0;
        }
    }
    mlx_key_hook (win, ft_exit , 0);
    mlx_hook(win, 17, 0, exit_buttons, 0);
    mlx_mouse_hook(win, mouse_hook, 0);
    mlx_loop(mlx);
}
 */