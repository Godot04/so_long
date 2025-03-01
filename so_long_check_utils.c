/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:41:08 by opopov            #+#    #+#             */
/*   Updated: 2025/02/24 17:10:23 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	top_row(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (x < data->number_of_tiles_x && data->objects_position[y][x] == '1')
		x++;
	if (x != data->number_of_tiles_x)
		return (1);
	return (0);
}

int	down_row(t_data *data)
{
	int	y;
	int	x;

	y = data->number_of_tiles_y - 1;
	x = 0;
	while (x < data->number_of_tiles_x && data->objects_position[y][x] == '1')
		x++;
	if (x != data->number_of_tiles_x)
		return (1);
	return (0);
}

int	left_column(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < data->number_of_tiles_y && data->objects_position[y][x] == '1')
		y++;
	if (y != data->number_of_tiles_y)
		return (1);
	return (0);
}

int	right_column(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = data->number_of_tiles_x - 1;
	while (y < data->number_of_tiles_y && data->objects_position[y][x] == '1')
		y++;
	if (y != data->number_of_tiles_y)
		return (1);
	return (0);
}

void	fill_v(char **map_copy, int y, int x, t_data *data)
{
	int	rows;
	int	columns;

	rows = data->number_of_tiles_y;
	columns = data->number_of_tiles_x;
	if (y < 0 || x < 0 || y >= rows || x >= columns
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	map_copy[y][x] = 'V';
	fill_v(map_copy, y + 1, x, data);
	fill_v(map_copy, y - 1, x, data);
	fill_v(map_copy, y, x + 1, data);
	fill_v(map_copy, y, x - 1, data);
}
