/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nswe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:02 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:04:02 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_xpm(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '.' && str[i + 1] == 'x')
			break ;
	i++;
	if ((str[i] == 'x' && str[i + 1] == 'p')
		&& (str[i + 2] == 'm' && !is_space(str[i + 3])))
		return (1);
	return (0);
}

int	ft_test(char *line, int start, int end)
{
	while (start < end)
	{
		if (is_space(line[start]))
			return (1);
		start++;
	}
	return (0);
}

char	*add_nswe(char *line, t_map *map)
{
	char	*send;
	int		i;
	int		len;

	i = 2;
	len = ft_strlen(line) - 1;
	while (is_space(line[i]))
		i++;
	while (is_space(line[len]))
		len--;
	if (line[i] != '.' || line[i + 1] != '/' || ft_test(line, i, len))
		clear_map_exit(map, ERROR_NSWE);
	if (!is_xpm(line))
		clear_map_exit(map, ERROR_NSWE);
	send = ft_substr(line, i, ft_strlen(line) - 1);
	return (send);
}
