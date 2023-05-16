/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:54 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:04:54 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	allocate_map(t_data *data, char **line)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = -1;
	while (line[++y])
	{
		x = 0;
		while (line[y][x])
			x++;
		if (data->x_size < x)
			data->x_size = x;
	}
	data->y_size = y;
	data->map = (int **)ft_calloc(y, sizeof(int *));
	while (++i < y)
		data->map[i] = (int *) ft_calloc(data->x_size, sizeof(int));
}

void	get_int_map(t_data *data, char **line)
{
	int	x;
	int	y;
	int	lock;

	y = -1;
	allocate_map(data, line);
	while (++y < data->y_size)
	{
		x = -1;
		lock = 0;
		while (++x < data->x_size)
		{
			if (!lock && (line[y][x] == '\0' || line[y][x] == '\n'))
				lock = 1;
			if (lock)
				data->map[y][x] = ' ';
			else
				data->map[y][x] = line[y][x];
		}
	}
}

void	image_controller(t_data *data)
{
	if (!data->imgs[0].img || !data->imgs[1].img
		|| !data->imgs[2].img || !data->imgs[3].img)
	{
		ft_putstr_fd_err("image error!\n", 2);
		exit(1);
	}
}

void	get_args(t_data *data, t_map *map)
{
	data->imgs[0].img = mlx_xpm_file_to_image(data->mlx,
			map->no, &data->imgs[0].width, &data->imgs[0].height);
	data->imgs[1].img = mlx_xpm_file_to_image(data->mlx,
			map->so, &data->imgs[1].width, &data->imgs[1].height);
	data->imgs[2].img = mlx_xpm_file_to_image(data->mlx,
			map->ea, &data->imgs[2].width, &data->imgs[2].height);
	data->imgs[3].img = mlx_xpm_file_to_image(data->mlx,
			map->we, &data->imgs[3].width, &data->imgs[3].height);
	image_controller(data);
	data->imgs[0].addr = mlx_get_data_addr(data->imgs[0].img,
			&data->imgs[0].bbp, &data->imgs[0].line_len, &data->imgs[0].endian);
	data->imgs[1].addr = mlx_get_data_addr(data->imgs[1].img,
			&data->imgs[1].bbp, &data->imgs[1].line_len, &data->imgs[1].endian);
	data->imgs[2].addr = mlx_get_data_addr(data->imgs[2].img,
			&data->imgs[2].bbp, &data->imgs[2].line_len, &data->imgs[2].endian);
	data->imgs[3].addr = mlx_get_data_addr(data->imgs[3].img,
			&data->imgs[3].bbp, &data->imgs[3].line_len, &data->imgs[3].endian);
	data->floor_color = (map->f.r << 16) + (map->f.g << 8) + map->f.b;
	data->ceil_color = (map->c.r << 16) + (map->c.g << 8) + map->c.b;
}

void	get_data(t_data *data, t_map *map)
{
	get_args(data, map);
	get_int_map(data, map->map);
}
