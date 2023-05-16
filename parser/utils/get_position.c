/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:27 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:04:27 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_position(t_map *data)
{
	int		i;
	int		k;
	int		t;

	t = 0;
	i = -1;
	while (data->map[++i])
	{
		k = -1;
		while (data->map[i][++k])
		{
			if (ft_strchr("ENWS", data->map[i][k]))
			{
				while (data->map[i][k] != "ENWS"[t])
					t++;
				data->ang = t * 90;
				data->map[i][k] = '0';
				data->y = i;
				data->x = k;
				return ;
			}
		}
	}
}
