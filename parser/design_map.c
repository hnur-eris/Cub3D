/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:48 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 11:04:29 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	design_map_continue(int i, char **line, t_map **map, int fd)
{
	if (i != 42 && *line != NULL)
	{
		close(fd);
		clear_map_exit(*map, ERROR_MAP);
	}
}

t_map	*design_map(int fd, t_map *map, int i)
{
	char	*line;

	while (((!map->no || !map->so) || !map->we
			|| !map->ea || map->f.sta != 1 || map->c.sta != 1))
	{
		i = get_line(&line, fd, 1);
		if (i != -1 && !ft_strncmp(line, "NO ", 3))
			map->no = add_nswe(line, map);
		else if (!ft_strncmp(line, "SO ", 3))
			map->so = add_nswe(line, map);
		else if (!ft_strncmp(line, "WE ", 3))
			map->we = add_nswe(line, map);
		else if (!ft_strncmp(line, "EA ", 3))
			map->ea = add_nswe(line, map);
		else if (!ft_strncmp(line, "F ", 2))
			map->f = add_pix((line + 2), map, map->f.sta, 0);
		else if (!ft_strncmp(line, "C ", 2))
			map->c = add_pix((line + 2), map, map->c.sta, 0);
		else
			design_map_continue(i, &line, &map, fd);
		map->many_line--;
		free(line);
	}
	return (map);
}
