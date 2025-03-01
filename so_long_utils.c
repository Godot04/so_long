/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:39:57 by opopov            #+#    #+#             */
/*   Updated: 2025/02/25 11:58:20 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	int	y;

	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	y = -1;
	while (++y < data->number_of_tiles_y)
		free(data->objects_position[y]);
	free(data->objects_position);
	free(data->mlx);
	exit(0);
	return (0);
}

int	ft_add_chars(t_data *data)
{
	int		y;
	int		fd;
	char	*str;
	int		x;

	fd = open(data->file_name, O_RDONLY);
	y = 0;
	if (data->number_of_tiles_x <= 0
		|| data->number_of_tiles_y <= 0 || fd == -1)
		return (-1);
	str = get_next_line(fd);
	while (str)
	{
		x = -1;
		while (++x < data->number_of_tiles_x)
			data->objects_position[y][x] = str[x];
		data->objects_position[y][data->number_of_tiles_x] = '\0';
		y++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	count_file_characters(t_data *data)
{
	int		fd;
	char	*str;

	data->number_of_tiles_x = 0;
	data->number_of_tiles_y = 0;
	fd = open(data->file_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: File doesn't exist.\n"));
	str = get_next_line(fd);
	while (str)
	{
		if (data->number_of_tiles_x == 0)
			data->number_of_tiles_x = ft_strlen(str);
		data->number_of_tiles_y++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	trigger_actions(t_data *data, int *new_x, int *new_y)
{
	if (data->objects_position[*new_y][*new_x] == '1')
		return (1);
	else if (data->objects_position[*new_y][*new_x] == 'E'
		&& data->flowers_exist <= 0)
	{
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	else if (data->objects_position[*new_y][*new_x] == 'E'
		&& data->flowers_exist > 0)
		return (1);
	else if (data->objects_position[*new_y][*new_x] == 'C')
	{
		data->objects_position[*new_y][*new_x] = '0';
		mlx_put_image_to_window(data->mlx, data->window, data->background,
			*new_x * TILE_SIZE, *new_y * TILE_SIZE);
		data->flowers_exist--;
	}
	return (0);
}

void	find_player_position(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->number_of_tiles_y)
	{
		x = -1;
		while (++x < data->number_of_tiles_x)
		{
			if (data->objects_position[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
		}
	}
	flower_count(data);
}
