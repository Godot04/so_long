/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opopov <opopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:44:48 by opopov            #+#    #+#             */
/*   Updated: 2025/02/25 10:56:28 by opopov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#define ESC 65307
#define TILE_SIZE 128

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*background;
	int		background_width;
	int		background_height;

	// Mountains
	void	*mountain;
	int		mountain_width;
	int		mountain_height;

	// Barn
	void	*barn;
	int		barn_width;
	int		barn_height;

	// Flower
	void	*flower;
	int		flower_width;
	int		flower_height;
	int		flowers_exist;

	// Player
	void	*player;
	int		player_width;
	int		player_height;
	int		player_x;
	int		player_y;

	// Other stuff
	int		background_bool;
	int		number_of_tiles_x;
	int		number_of_tiles_y;
	char	**objects_position;
	int		number_of_movements;
	char	*file_name;
}	t_data;

int		trigger_actions(t_data *data, int *new_x, int *new_y);
int		close_window(t_data *data);
void	find_player_position(t_data *data);
int		count_file_characters(t_data *data);
int		ft_add_chars(t_data *data);
int		ft_check(t_data *data);
int		ft_strlen(char *str);
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_itoa(int n);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_ber(const char *filename);
int		top_row(t_data *data);
int		down_row(t_data *data);
int		left_column(t_data *data);
int		right_column(t_data *data);
void	flower_count(t_data *data);
void	display_moves(t_data *data);
int		allocates_memory(t_data *data);
int		window_create(t_data *data);
void	free_memory(t_data *data);
void	objects_draw(t_data *data);
void	fill_v(char **map_copy, int y, int x, t_data *data);
