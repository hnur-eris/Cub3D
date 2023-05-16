/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:44 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:04:44 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_putstr_fd_err(char *s, int fd)
{
	int	i;

	if (s != 0)
	{
		i = 0;
		while (s[i] != 0)
			write(fd, &s[i++], 1);
	}
	exit(1);
}

int	check_characters(t_map *data)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	a = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if ((!is_space(data->map[i][j])) &&
				(!ft_strchr("01NSEW", data->map[i][j])))
				clear_map_exit(data, ERROR_VAL);
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
				data->map[i][j] == 'W' || data->map[i][j] == 'E')
				a++;
		}
	}
	if (a != 1)
		ft_putstr_fd_err("Error\nMore than one char\n", 2);
	return (0);
}

int	checking_zero(char **map, int y, int x)
{
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' && condition(map, y, x))
				return (1);
			x++;
		}
	}
	return (0);
}

int	check_double_map(char **map, int y, int x)
{
	int	key;

	key = 0;
	while (map[y])
	{
		if (key == 0 && (!ft_strchr("01NSEW", map[y][x])))
			key++;
		else if ((ft_strchr(" 01NSEW", map[y][x])) &&
			key == 1)
			return (1);
		y++;
	}
	return (0);
}

int	check_wall(char **map, int y, int x)
{
	if (check_double_map(map, y, x))
		return (1);
	if (checking_zero(map, y - 1, x))
		return (1);
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '\n' && is_space(map[y][x]))
				map[y][x] = '1';
			x++;
		}
		y++;
	}
	return (0);
}
