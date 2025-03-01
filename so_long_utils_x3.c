/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_x3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:22:32 by opopov            #+#    #+#             */
/*   Updated: 2025/02/25 10:54:22 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	objects_draw(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->number_of_tiles_y)
	{
		x = -1;
		while (++x < data->number_of_tiles_x)
		{
			if (data->objects_position[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->mountain,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (data->objects_position[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->flower,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (data->objects_position[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->barn,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (data->objects_position[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->player,
					data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
		}
	}
}

void	flower_count(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (++y < data->number_of_tiles_y)
	{
		x = -1;
		while (++x < data->number_of_tiles_x)
		{
			if (data->objects_position[y][x] == 'C')
				data->flowers_exist++;
		}
	}
}
