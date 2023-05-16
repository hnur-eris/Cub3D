/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:14:36 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:14:36 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	map_check_cub(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != '1' && !is_space(str[i]) && str[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

char	*start_read(int fd)
{
	char	*line;

	while (get_line(&line, fd, 0) != -1)
	{
		if (!map_check_cub(line, 0))
			return (NULL);
		else if (ft_strchr(line, '1'))
			return (line);
		free(line);
	}
	return (NULL);
}

int	add_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = start_read(fd);
	if (!line || line == NULL)
		return (1);
	map->map = ft_calloc(sizeof(char *), map->many_line);
	while (i < map->many_line)
	{
		map->map[i] = line;
		if (line != NULL && ft_strchr(line, '\t'))
			return (1);
		line = get_next_line(fd);
		i++;
	}
	if (line)
		free(line);
	return (0);
}
