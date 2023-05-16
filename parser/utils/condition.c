/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:17 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:04:19 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	map_len(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	condition(char **map, int y, int x)
{
	if (y == 0 || x == 0)
		return (1);
	if (x != 0 && is_space(map[y][x + 1]))
		return (1);
	else if (map[y][x + 1] == 0 || is_space(map[y][x + 1]))
		return (1);
	else if (!(y == 0 && x > (int)ft_strlen(map[y - 1]))
		&& (is_space(map[y + 1][x])))
		return (1);
	else if (!(y == map_len(map) && x > (int)ft_strlen(map[y + 1]))
		&& (is_space(map[y + 1][x])))
		return (1);
	return (0);
}
