/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:03:49 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:03:49 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start_game(t_data *data, t_map *map)
{
	data->pos.x = map->x;
	data->pos.y = map->y;
	data->look = (map->ang) * ANLE_TO_RADIAN;
	render(data);
}
