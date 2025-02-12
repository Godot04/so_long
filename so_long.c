/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:59:29 by opopov            #+#    #+#             */
/*   Updated: 2025/02/11 17:19:51 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #define GREEN 0xACD42B

void background_draw(t_data *data)
{
	// draw background
	if (data->background_bool == 0)
	{
		for (int y = 0; y < NUMBER_OF_TILES_Y * TILE_SIZE; y += TILE_SIZE)
		{
			for (int x = 0; x < NUMBER_OF_TILES_X * TILE_SIZE; x += TILE_SIZE)
			{
				mlx_put_image_to_window(data->mlx, data->window, data->background, x, y);
			}
		}
	}

	//draw objects
	for (int y = 0; y < NUMBER_OF_TILES_Y; y++)
		for (int x = 0; x < NUMBER_OF_TILES_X; x++)
		{
			if (data->objects_pisition[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->mountain,
							x * TILE_SIZE, y * TILE_SIZE);
			else if (data->objects_pisition[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->flower,
							x * TILE_SIZE, y * TILE_SIZE);
			else if (data->objects_pisition[x][y] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->barn,
							x * TILE_SIZE, y * TILE_SIZE);
		}

	// delete this at the end of the project
	if (data->flowers_exist == 0)
	{
		system("paplay Textures/000029c2.wav &");
		data->flowers_exist--;
	}
}

int p_movement(int key, t_data *data)
{
	data->background_bool = 1;
	int new_x = data->player_x;
	int new_y = data->player_y;
	if (key == 119)
		new_y -= 1;
	else if (key == 115)
		new_y += 1;
	else if (key == 97)
		new_x -= 1;
	else if (key == 100)
		new_x += 1;
	int tr = trigger_actions(data, &new_x, &new_y);
	if (tr != 0)
		return (1);
	mlx_put_image_to_window(data->mlx, data->window, data->background,
							data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
	data->player_x = new_x;
	data->player_y = new_y;
	background_draw(data);
	mlx_put_image_to_window(data->mlx, data->window, data->player,
							data->player_x * TILE_SIZE, data->player_y * TILE_SIZE);
	return (0);
}
void initialize_objects(t_data *data)
{
	data->background = mlx_xpm_file_to_image(data->mlx, "Textures/Background.xpm", &data->background_width, &data->background_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "Textures/Cow.xpm", &data->player_width, &data->player_height);
	data->mountain = mlx_xpm_file_to_image(data->mlx, "Textures/Mountains.xpm", &data->mountain_width, &data->mountain_height);
	data->flower = mlx_xpm_file_to_image(data->mlx, "Textures/Flower.xpm", &data->flower_width, &data->flower_height);
	data->barn = mlx_xpm_file_to_image(data->mlx, "Textures/Barn.xpm", &data->barn_width, &data->barn_height);
	if (!data->background || !data->player || !data->mountain || !data->flower || !data->barn)
		exit(1);

	// fill the array
	for (int y = 0; y < NUMBER_OF_TILES_Y; y++)
		for (int x = 0; x < NUMBER_OF_TILES_X; x++)
			data->objects_pisition[x][y] = '0';
}

int main()
{
	t_data data;
	count_file_characters(&data); 
	data.background_bool = 0;
	data.flowers_exist = 0;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.window = mlx_new_window(data.mlx, NUMBER_OF_TILES_X * TILE_SIZE,
								NUMBER_OF_TILES_Y * TILE_SIZE, "So long");
	if (!data.window)
		return (1);
	initialize_objects(&data);

	// set objects position
	data.objects_pisition[2][2] = 'C';
	data.objects_pisition[2][4] = 'C';
	data.objects_pisition[4][1] = 'C';
	data.objects_pisition[1][1] = '1';
	data.objects_pisition[7][3] = '1';
	data.objects_pisition[9][3] = 'E';
	data.objects_pisition[5][2] = 'P';

	find_player_position(&data);
	background_draw(&data);
	mlx_hook(data.window, 17, 0, close_window, &data);
	mlx_key_hook(data.window, p_movement, &data);
	mlx_loop(data.mlx);
	return (0);
}
