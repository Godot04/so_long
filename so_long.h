/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:13:04 by opopov            #+#    #+#             */
/*   Updated: 2025/02/11 17:19:40 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#define ESC 65307
#define TILE_SIZE 128
#define NUMBER_OF_TILES_X 10
#define NUMBER_OF_TILES_Y 5

typedef struct s_data
{
	void *mlx;
	void *window;
	void *background;
	int background_width;
	int background_height;

	// Mountains
	void *mountain;
	int mountain_width;
	int mountain_height;

	// Barn
	void *barn;
	int barn_width;
	int barn_height;

	// Flower
	void *flower;
	int flower_width;
	int flower_height;
	int flowers_exist;

	// Player
	void *player;
	int player_width;
	int player_height;
	int player_x;
	int player_y;

	// Other stuff
	int background_bool;
	char objects_pisition[NUMBER_OF_TILES_X][NUMBER_OF_TILES_Y];
	int number_of_tiles_x;
	int number_of_tiles_y;
}	t_data;

int		trigger_actions(t_data *data, int *new_x, int *new_y);
int		close_window(t_data *data);
void	find_player_position(t_data *data);
int		count_file_characters(t_data *data);
