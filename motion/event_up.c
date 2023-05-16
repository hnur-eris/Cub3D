/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:05:25 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:05:25 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	event_up(int key, t_data *data)
{
	if (key == 13 || key == 119)
		data->keys.w = 1;
	else if (key == 1 || key == 115)
		data->keys.s = 1;
	else if (key == 0 || key == 97)
		data->keys.a = 1;
	else if (key == 2 || key == 100)
		data->keys.d = 1;
	else if (key == 123)
		data->keys.left = 1;
	else if (key == 124)
		data->keys.right = 1;
	else if (key == 257)
		data->keys.speed = 1;
	else if (key == 53 || key == 65307)
		exit(0);
	return (0);
}
