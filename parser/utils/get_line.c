/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:22 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:04:22 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_line(char **line, int fd, int key)
{
	char	*str;
	int		end_i;
	size_t	i;

	str = get_next_line(fd);
	if (!str)
		return (-1);
	if (key != 1)
	{
		*line = str;
		return (1);
	}
	i = 0;
	while (is_space(str[i]))
		i++;
	end_i = ft_strlen(str) - 1;
	while (is_space(str[end_i]))
		end_i--;
	*line = ft_substr(str, i, end_i + 1);
	if (i == ft_strlen(str))
		i = 42;
	else
		i = 1;
	free(str);
	return (i);
}
