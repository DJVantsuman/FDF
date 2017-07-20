/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/20 11:32:27 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    get_pixel_color(char *s, t_pixel *pixel)
{
    int     i;
    int     j;
    char    *color;

    i = 0;
    j = 0;
    color = (char *)malloc(sizeof(char) * 7);
    while (s[i] != 'x' && s[i] != ' ' && s[i] != '\0')
        i++;
    if (s[i] == ' ' || s[i] == '\0')
    {
        pixel->col_R = 255;
        pixel->col_G = 255;
        pixel->col_B = 255;
        return ;
    }
    i++;
    while (s[i] != ' ' && s[i] != '\0')
    {
        color[j] = s[i];
        i++;
        j++;
    }
    color[j] = '\0';
    get_color(color, pixel);
    printf("1\n");
}

void    create_struct(t_pixel **pixel, char **map, int i, int t)
{
    int x;
    int j;

    while (map[i])
    {
        x = 0;
        j = 0;
        while (map[i][j])
        {
            pixel[t] = (t_pixel *)malloc(sizeof(t_pixel));
            pixel[t]->x = x;
            pixel[t]->y = i;
            pixel[t]->z = -ft_atoi(map[i] + j);
            get_pixel_color(map[i] + j, pixel[t]);
            x++;
            t++;
            while (map[i][j] != ' ' && map[i][j] != '\0')
                j++;
            if (map[i][j] == '\0')
                break ;
            while (map[i][j] == ' ')
                j++;
        }
        i++;
    }
}

int     count_pixels(char **map)
{
    int count;
    int i;
    int j;

    i = 0;
    count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            count++;
            while (map[i][j] != ' ' && map[i][j] != '\0')
                j++;
            if (map[i][j] == '\0')
                break ;
            while (map[i][j] == ' ')
                j++;
        }
        i++;
    }
    return (count);
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
    int     l;
    char    **map;
    t_pixel **pixel;

    map = NULL;
    if (ac == 2)
    {
        write_map(&map, av[1]);
        l = count_pixels(map);
        pixel = (t_pixel **)malloc(sizeof(t_pixel *) * (l + 1));
        pixel[l] = NULL;
        create_struct(pixel, map, 0, 0);
        create_image(pixel, map);
    } else
        write(1, "ERROR: not valid file.\n", 23);





//    int i = 0;
//    while (pixel[i])
//    {
//        printf("pixel %d: x = %d, y = %d, z = %d, color = %s\n", i, pixel[i]->x, pixel[i]->y, pixel[i]->z, pixel[i]->color);
//        i++;
//    }

	return (0);
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
