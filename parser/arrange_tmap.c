/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_tmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:38 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:04:38 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	many_line(int fd)
{
	int		i;
	char	*line;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}

void	value_zero(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	map->f.sta = 0;
	map->c.sta = 0;
	map->many_line = many_line(fd);
	close(fd);
}

t_map	*arrange_tmap(char *file)
{
	t_map	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(ERROR_FD, 2);
		exit(1);
	}
	map = ft_calloc(sizeof(t_map), 1);
	value_zero(file, map);
	map = design_map(fd, map, 0);
	if (add_map(fd, map))
	{
		close(fd);
		clear_map_exit(map, ERROR_TAB);
	}
	close(fd);
	return (map);
}
