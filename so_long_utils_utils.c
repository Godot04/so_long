/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:17:36 by opopov            #+#    #+#             */
/*   Updated: 2025/02/25 11:07:39 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_memory(t_data *data)
{
	int	y;

	y = -1;
	while (++y < data->number_of_tiles_y)
		free(data->objects_position[y]);
	free(data->objects_position);
}

int	window_create(t_data *data)
{
	data->background_bool = 0;
	data->number_of_movements = 0;
	data->flowers_exist = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->window = mlx_new_window(data->mlx,
			data->number_of_tiles_x * TILE_SIZE,
			data->number_of_tiles_y * TILE_SIZE, "So long");
	if (!data->window)
		return (1);
	return (0);
}

int	allocates_memory(t_data *data)
{
	int	y;

	data->objects_position = malloc(sizeof(char *) * data->number_of_tiles_y);
	if (!data->objects_position)
		return (1);
	y = -1;
	while (++y < data->number_of_tiles_y)
	{
		data->objects_position[y] = malloc(sizeof(char)
				* (data->number_of_tiles_x + 1));
		if (!data->objects_position[y])
			return (1);
	}
	return (0);
}

void	display_moves(t_data *data)
{
	char	*moves_counter;
	int		text_x;
	int		text_y;

	text_x = 10;
	text_y = 20;
	moves_counter = ft_itoa(data->number_of_movements);
	mlx_set_font(data->mlx, data->window, "9x15bold");
	mlx_string_put(data->mlx, data->window, text_x,
		text_y, 0x000000, "Moves: ");
	mlx_string_put(data->mlx, data->window, text_x + 60,
		text_y, 0x000000, "    ");
	mlx_string_put(data->mlx, data->window, text_x, text_y,
		0xFFFFFF, "Moves: ");
	mlx_string_put(data->mlx, data->window, text_x + 60, text_y,
		0xFFFFFF, moves_counter);
	ft_printf("Moves: %d\n", data->number_of_movements);
	free(moves_counter);
}

int	ft_ber(const char *filename)
{
	const char	*tmp;

	tmp = ft_strrchr(filename, '.');
	if (tmp && ft_strcmp(tmp, ".ber") == 0)
		return (0);
	return (1);
}
