/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:03:26 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:03:26 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_wall(t_data *data, float distance, t_found cord_data, int index)
{
	int		draw;
	float	rate_i;
	int		start;
	int		end;

	draw = (5 / distance) * (WIN_HEIGHT * 0.3f);
	rate_i = (float)data->imgs[data->active_img].height / draw;
	start = (WIN_HEIGHT - draw) / 2;
	end = 0;
	if (start < 0)
	{
		draw += start;
		end = -start;
	}
	while (draw-- > end)
		image_put_pixel(&data->screen, index, draw + start,
			image_get_pixel(&data->imgs[data->active_img],
				data->imgs[data->active_img].width * cord_data.rate,
				draw * rate_i));
}
