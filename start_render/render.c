/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:03:41 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:03:41 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	raycast(t_data *data, float angle, int pixels)
{
	float		cos_value;
	float		sin_value;
	t_player	dir;

	cos_value = cosf(angle + data->look);
	sin_value = sinf(angle + data->look);
	dir.x = (cos_value > 0) * 2 - 1;
	dir.y = (sin_value > 0) * 2 - 1;
	dir.angle = angle;
	look_slope(data, sin_value / cos_value, &dir, pixels);
}

void	fill_screen(t_data *data)
{
	int		x;
	int		y;
	int		middle;

	middle = data->screen.height / 2;
	y = -1;
	while (++y < middle)
	{
		x = -1;
		while (++x < data->screen.width)
			image_put_pixel(&data->screen, x, y, data->ceil_color);
	}
	while (++y < data->screen.height)
	{
		x = -1;
		while (++x < data->screen.width)
			image_put_pixel(&data->screen, x, y, data->floor_color);
	}
}

void	render(t_data *data)
{
	const float	view_angle = 1.0f;
	const float	add = view_angle / WIN_WIDTH;
	float		angle;
	int			pixels;

	fill_screen(data);
	pixels = WIN_WIDTH;
	angle = -(view_angle / 2);
	while (pixels--)
	{
		raycast(data, angle, pixels);
		angle += add;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->screen.img, 0, 0);
}
