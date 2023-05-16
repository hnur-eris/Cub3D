/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_slope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:03:35 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:03:35 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static float	get_distance(t_vector2f a, t_vector2f b)
{
	float	x;
	float	y;

	x = a.x - b.x;
	y = a.y - b.y;
	return (sqrt(x * x + y * y));
}

static t_found	look_horizontal(t_data *data, float f_slope, int add)
{
	float	f_add;
	int		i;
	float	y;

	i = data->pos.x;
	i += add;
	f_add = data->pos.y - (f_slope * data->pos.x);
	while (1)
	{
		y = f_slope * (i + (add < 0)) + f_add;
		if (y < 0 || (int)y >= data->y_size || i < 0 || i >= data->x_size)
			return ((t_found){0x7FFFFFFF, 0, 0, 0});
		if (data->map[(int)y][i] == '1')
		{
			return ((t_found){get_distance((t_vector2f){i + (add < 0), y}, \
			data->pos), y - (int)y, i + (add < 0), y});
		}
		i += add;
	}
}

static t_found	look_vertical(t_data *data, float f_slope, int add)
{
	float	f_add;
	int		i;
	float	x;

	i = data->pos.y;
	i += add;
	f_add = data->pos.x - (f_slope * data->pos.y);
	while (1)
	{
		x = f_slope * (i + (add < 0)) + f_add;
		if (x < 0 || (int)x >= data->x_size || i < 0 || i >= data->y_size)
			return ((t_found){0x7FFFFFFF, 0, 0, 0});
		if (data->map[i][(int)x] == '1')
		{
			return ((t_found){get_distance((t_vector2f){x, i + (add < 0)}, \
				data->pos), x - (int)x, x, i + (add < 0)});
		}
		i += add;
	}
}

void	look_slope(t_data *data, float slope, t_player *dir, int index)
{
	t_found	vertical;
	t_found	horizontal;

	horizontal = look_horizontal(data, slope, dir->x);
	vertical = look_vertical(data, 1 / slope, dir->y);
	if (horizontal.distance > vertical.distance)
	{
		data->active_img = dir->y > 0;
		if (dir->y < 0)
			vertical.rate = 1 - vertical.rate;
		draw_wall(data, vertical.distance * cos(dir->angle),
			vertical, index);
	}
	else
	{
		data->active_img = 2 + (dir->x > 0);
		if (dir->x > 0)
			horizontal.rate = 1 - horizontal.rate;
		draw_wall(data, horizontal.distance * cos(dir->angle),
			horizontal, index);
	}
}
