/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:34:07 by opopov            #+#    #+#             */
/*   Updated: 2025/02/25 11:23:02 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	background_draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	if (data->background_bool == 0)
	{
		while (y < data->number_of_tiles_y * TILE_SIZE)
		{
			x = 0;
			while (x < data->number_of_tiles_x * TILE_SIZE)
			{
				mlx_put_image_to_window(data->mlx, data->window,
					data->background, x, y);
				x += TILE_SIZE;
			}
			y += TILE_SIZE;
		}
	}
	objects_draw(data);
}

void	p_movement_2(int new_x, int new_y, t_data *data)
{
	if ((data->player_x - new_x) != 0 || (data->player_y - new_y) != 0)
		data->number_of_movements++;
	data->player_x = new_x;
	data->player_y = new_y;
	background_draw(data);
	mlx_put_image_to_window(data->mlx, data->window, data->player,
		data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
	display_moves(data);
}

int	p_movement(int key, t_data *data)
{
	int	new_x;
	int	new_y;
	int	tr;

	data->background_bool = 1;
	new_x = data->player_x;
	new_y = data->player_y;
	if (key == 119 || key == 65362)
		new_y -= 1;
	else if (key == 115 || key == 65364)
		new_y += 1;
	else if (key == 97 || key == 65361)
		new_x -= 1;
	else if (key == 100 || key == 65363)
		new_x += 1;
	else if (key == ESC)
		close_window(data);
	tr = trigger_actions(data, &new_x, &new_y);
	if (tr != 0)
		return (1);
	mlx_put_image_to_window(data->mlx, data->window, data->background,
		data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
	p_movement_2(new_x, new_y, data);
	return (0);
}

void	initialize_objects(t_data *data)
{
	data->background = mlx_xpm_file_to_image(data->mlx,
			"Textures/Background.xpm", &data->background_width,
			&data->background_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "Textures/Cow.xpm",
			&data->player_width, &data->player_height);
	data->mountain = mlx_xpm_file_to_image(data->mlx, "Textures/Mountains.xpm",
			&data->mountain_width, &data->mountain_height);
	data->flower = mlx_xpm_file_to_image(data->mlx, "Textures/Flower.xpm",
			&data->flower_width, &data->flower_height);
	data->barn = mlx_xpm_file_to_image(data->mlx, "Textures/Barn.xpm",
			&data->barn_width, &data->barn_height);
	mlx_string_put(data->mlx, data->window, 20, 20, 0xFFFFFF, "Moves: ");
	if (!data->background || !data->player || !data->mountain
		|| !data->flower || !data->barn)
	{
		ft_printf("Error: Failed to load images.\n");
		close_window(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("Error: Invalid search.\n"));
	data.file_name = argv[1];
	if ((ft_ber(data.file_name)))
		return (ft_printf("Error: Map file must have a .ber extension.\n"));
	count_file_characters(&data);
	if (data.number_of_tiles_x <= 0 || data.number_of_tiles_y <= 0)
		return (1);
	if (allocates_memory(&data))
		return (1);
	if (window_create(&data))
		return (1);
	initialize_objects(&data);
	ft_add_chars(&data);
	if ((ft_check(&data)))
		close_window(&data);
	background_draw(&data);
	display_moves(&data);
	mlx_hook(data.window, 17, 0, close_window, &data);
	mlx_key_hook(data.window, p_movement, &data);
	mlx_loop(data.mlx);
	free_memory(&data);
}
