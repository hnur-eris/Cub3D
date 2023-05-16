/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:02:55 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 14:30:06 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	init_image(t_data *data)
{
	data->screen.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->screen.width = WIN_WIDTH;
	data->screen.height = WIN_HEIGHT;
	data->screen.addr = mlx_get_data_addr(data->screen.img, &data->screen.bbp, \
	&data->screen.line_len, &data->screen.endian);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	if (ac == 2 && !ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 5))
	{
		map = arrange_tmap(av[1]);
		check_characters(map);
		if (check_wall(map->map, 0, 0))
			clear_map_exit(map, ERROR_MAP);
		get_position(map);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "...");
		get_data(&data, map);
		init_image(&data);
		start_game(&data, map);
		motion_setting(&data);
		mlx_loop(data.mlx);
	}
	else
		ft_putstr_fd("Error\nArgument Error\n", 2);
}
