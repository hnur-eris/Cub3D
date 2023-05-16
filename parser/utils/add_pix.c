/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:04:11 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:04:11 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	difch(char **sp_pix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (sp_pix[i][j])
		{
			if (!ft_isdigit(sp_pix[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_pixel	add_pix(char *line, t_map *data, int sta, int i)
{
	t_pixel	pix;
	char	**sp_pix;

	pix.sta = sta;
	sp_pix = ft_split(line, ',');
	while (sp_pix[i])
		i++;
	if (i == 3 && !difch(sp_pix) && sta == 0)
	{
		pix.r = ft_atoi(sp_pix[0]);
		pix.g = ft_atoi(sp_pix[1]);
		pix.b = ft_atoi(sp_pix[2]);
		pix.sta++;
	}
	if ((!(pix.r <= 255 && pix.r >= 0)) || (!(pix.g <= 255 && pix.g >= 0))
		|| (!(pix.b <= 255 && pix.b >= 0)) || (i != 3 || difch(sp_pix)))
	{
		free_array(sp_pix);
		clear_map_exit(data, ERROR_RGB);
	}
	free_array(sp_pix);
	return (pix);
}
