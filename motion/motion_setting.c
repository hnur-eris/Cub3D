/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:05:30 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:05:30 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_screen(void *tmp)
{
	(void)tmp;
	exit(0);
}

void	motion_setting(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, event_up, data);
	mlx_hook(data->mlx_win, 3, 0, event_down, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_hook(data->mlx_win, 17, 0, exit_screen, 0);
}
