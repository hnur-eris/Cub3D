/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:03:30 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:03:30 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	image_put_pixel(t_image *img, int x, int y, unsigned int color)
{
	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return ;
	*((int *)(img->addr + (y * img->line_len) \
	+ (x * 4))) = color;
}

int	image_get_pixel(t_image *img, int x, int y)
{
	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return (0);
	return (*((int *)(img->addr + (y * img->line_len) \
	+ (x * 4))));
}
