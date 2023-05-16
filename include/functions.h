/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <haeris@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:16:26 by haeris            #+#    #+#             */
/*   Updated: 2023/05/12 10:16:26 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "all_structs.h"

char			*add_nswe(char *line, t_map *map);
t_pixel			add_pix(char *line, t_map *data, int sta, int i);
int				add_map(int fd, t_map *map);
int				get_line(char **line, int fd, int key);
int				check_characters(t_map *data);
int				check_wall(char **map, int y, int x);
void			ft_putstr_fd_err(char *s, int fd);
void			get_position(t_map *map);
t_map			*arrange_tmap(char *file);
t_map			*design_map(int fd, t_map *map, int i);
void			get_data(t_data *data, t_map *map);
int				condition(char **map, int y, int x);

void			clear_map_exit(t_map *data, char *str);
void			free_array(char **str);
int				is_space(char c);

void			start_game(t_data *data, t_map *map);
void			render(t_data *data);
int				image_get_pixel(t_image *img, int x, int y);
void			image_put_pixel(t_image *img, int x, int y, unsigned int color);
void			draw_wall(t_data *data, float distance,
					t_found cord_data, int index);
void			look_slope(t_data *data, float slope, t_player *dir, int index);

int				event_down(int key, t_data *data);
int				event_up(int key, t_data *data);
int				update(t_data *data);
void			move(t_data *data, t_vector2f move);
void			motion_setting(t_data *data);
int				condition(char **map, int y, int x);

#endif