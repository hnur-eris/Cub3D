/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:05:36 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:05:36 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	collision_detect(t_data *data, t_vector2f pos)
{
	float	size;

	size = 0.2f;
	return (data->map[(int)(pos.y + size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x + size)] != '1'
		&& data->map[(int)(pos.y - size)][(int)(pos.x - size)] != '1'
		&& data->map[(int)(pos.y + size)][(int)(pos.x - size)] != '1');
}

void	move(t_data *data, t_vector2f move)
{
	if (collision_detect(data,
			(t_vector2f){data->pos.x + move.x, data->pos.y}))
		data->pos.x += move.x;
	if (collision_detect(data,
			(t_vector2f){data->pos.x, data->pos.y + move.y}))
		data->pos.y += move.y;
}
