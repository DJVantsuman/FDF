/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:50:46 by itsuman           #+#    #+#             */
/*   Updated: 2017/07/23 15:05:51 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_pixel_color(char *s, t_pixel *pixel, int i, int j)
{
	char	*color;

	color = (char *)malloc(sizeof(char) * 7);
	check_pixel(s);
	while (s[i] == ' ')
		i++;
	while (s[i] != 'x' && s[i] != ' ' && s[i] != '\0')
		i++;
	if (s[i] == ' ' || s[i] == '\0')
	{
		pixel->color = 16777215;
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
}

void	create_struct(t_pixel **pixel, char **map, int i, int t)
{
	int	x;
	int	j;

	while (map[i])
	{
		x = 0;
		j = 0;
		while (map[i][j])
		{
			pixel[t] = (t_pixel *)malloc(sizeof(t_pixel));
			pixel[t]->x = x;
			pixel[t]->y = i;
			check_z(map[i] + j, pixel[t]);
			get_pixel_color(map[i] + j, pixel[t], 0, 0);
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

int		count_pixels(char **map)
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

void	write_map(char ***map, char *file)
{
	int		fd;
	char	*line;
	char	*str;
	char	*del;

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
		write(2, "\nERROR: wrong file.\n", 20);
		exit(2);
	}
}

int		main(int ac, char **av)
{
	int		l;
	char	**map;
	t_pixel	**pixel;

	map = NULL;
	if (ac == 2)
	{
		write_map(&map, av[1]);
		l = count_pixels(map);
		if (l == 0)
			error("\nERROR. Wrong or empty file.\n");
		if (l != leght_map(map, 'x') * leght_map(map, 'y'))
		{
			write(2, "\nERROR: wrong file.\n", 20);
			exit(2);
		}
		pixel = (t_pixel **)malloc(sizeof(t_pixel *) * (l + 1));
		pixel[l] = NULL;
		create_struct(pixel, map, 0, 0);
		create_image(pixel, map);
	}
	else
		write(2, "ERROR: not valid file.\n", 23);
	return (0);
}
