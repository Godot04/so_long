/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:49:41 by opopov            #+#    #+#             */
/*   Updated: 2025/02/24 17:26:22 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_props(t_data *data)
{
	int	player_position;
	int	collectible;
	int	exit;
	int	x;
	int	y;

	collectible = 0;
	player_position = 0;
	exit = 0;
	y = -1;
	while (++y < data->number_of_tiles_y)
	{
		x = -1;
		while (++x < data->number_of_tiles_x)
		{
			if (data->objects_position[y][x] == 'C')
				collectible++;
			if (data->objects_position[y][x] == 'E')
				exit++;
			if (data->objects_position[y][x] == 'P')
				player_position++;
		}
	}
	return (!collectible || player_position != 1 || exit != 1);
}

int	is_valid_path_check(t_data *data, char **map_copy)
{
	int	y;
	int	x;
	int	z;

	y = -1;
	while (++y < data->number_of_tiles_y)
	{
		x = -1;
		while (++x < data->number_of_tiles_x)
		{
			if ((data->objects_position[y][x] == 'C'
				|| data->objects_position[y][x] == 'E')
				&& map_copy[y][x] != 'V')
			{
				z = -1;
				while (++z < data->number_of_tiles_y)
					free(map_copy[z]);
				free(map_copy);
				return (1);
			}
		}
	}
	return (0);
}

int	is_valid_path(t_data *data)
{
	char	**map_copy;
	int		y;

	find_player_position(data);
	map_copy = malloc(sizeof(char *) * data->number_of_tiles_y);
	if (!map_copy)
		return (1);
	y = -1;
	while (++y < data->number_of_tiles_y)
	{
		map_copy[y] = malloc(sizeof(char) * (data->number_of_tiles_x + 1));
		if (!map_copy[y])
			return (1);
		ft_strlcpy(map_copy[y], data->objects_position[y],
			data->number_of_tiles_x + 1);
	}
	fill_v(map_copy, data->player_y, data->player_x, data);
	if ((is_valid_path_check(data, map_copy)))
		return (1);
	y = -1;
	while (++y < data->number_of_tiles_y)
		free(map_copy[y]);
	free(map_copy);
	return (0);
}

int	check_map_fills(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->number_of_tiles_y)
	{
		x = -1;
		while (++x < data->number_of_tiles_x)
		{
			if (data->objects_position[y][x] != 'C'
				&& data->objects_position[y][x] != '0'
				&& data->objects_position[y][x] != '1'
				&& data->objects_position[y][x] != 'E'
				&& data->objects_position[y][x] != 'P')
				return (1);
		}
	}
	return (0);
}

int	ft_check(t_data *data)
{
	if ((top_row(data)) || (down_row(data))
		|| (right_column(data)) || (left_column(data)))
	{
		ft_printf("Error: Invalid map.\n");
		return (1);
	}
	else if (check_map_fills(data))
	{
		ft_printf("Error: Invalid map fills.\n");
		return (1);
	}
	else if ((ft_count_props(data)))
	{
		ft_printf("Error: Invalid number of props.\n");
		return (1);
	}
	else if ((is_valid_path(data)))
	{
		ft_printf("Error: No valid paths are exist.\n");
		return (1);
	}
	else
		return (0);
}
