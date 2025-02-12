/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:32:21 by opopov            #+#    #+#             */
/*   Updated: 2025/02/11 17:12:40 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_file_characters(t_data *data)
{
	int fd;
	int x = 0;
	int y = 0;
	char *str;
	open("Maps/map1.ber", fd);
	while ((str = get_next_line(fd)))
	{
		for (int i = 0; str[i]; i++)
			x++;
		y++;
	}
	data->number_of_tiles_x = x;
	data->number_of_tiles_y = y;
	close(fd);
}

int	trigger_actions(t_data *data, int *new_x, int *new_y)
{
	if (data->objects_pisition[*new_x][*new_y] == '1')
		return (1);
	else if (data->objects_pisition[*new_x][*new_y] == 'E' && data->flowers_exist <= 0)
	{
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	else if (data->objects_pisition[*new_x][*new_y] == 'E' && data->flowers_exist > 0)
		return (1);
	else if (data->objects_pisition[*new_x][*new_y] == 'C')
	{
		data->objects_pisition[*new_x][*new_y] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->background,
								*new_x * TILE_SIZE, *new_y * TILE_SIZE);
		data->flowers_exist--;
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	find_player_position(t_data *data)
{
	for (int y = 0; y < NUMBER_OF_TILES_Y; y++)
	{
		for (int x = 0; x < NUMBER_OF_TILES_X; x++)
		{
			if (data->objects_pisition[x][y] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
		}
	}

	//flower count
	for (int y = 0; y < NUMBER_OF_TILES_Y; y++)
		for (int x = 0; x < NUMBER_OF_TILES_X; x++)
			if (data->objects_pisition[x][y] == 'C')
				data->flowers_exist++;
}
