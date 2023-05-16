/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:03:08 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:03:08 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clear_map_exit(t_map *data, char *str)
{
	int	i;

	ft_putstr_fd(str, 2);
	if (data->no)
		free(data->no);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->so)
		free(data->so);
	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	if (data->map)
		free(data->map);
	free(data);
	exit (1);
}
