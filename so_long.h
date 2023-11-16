/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2023/11/16 15:07:32 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;
	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_game;

int		exit_point(t_game *game);
int		map_reading(t_game *game, char **argv);
int		controls_working(int command, t_game *game);
void	adding_in_graphics(t_game *game);
void	place_graphics(t_game *game, int width, int height);
int		place_images_in_game(t_game *game);
void	if_walls(t_game *game);
void	character_valid(t_game *game);
void	check_errors(t_game *game);
int		right_move(t_game *game, int i, int j);
int		width_of_map(char *string);
int		check_valid_width(t_game *game);

void 	copy_map(t_game *game);
int		ft_arraycount(t_game *game);
void	check_exit_accesible(char **map_copy, int i, int j);



//void	check_exit(t_game *game, int x, int y);
//void	check_items(t_game *game, int x, int y);

#endif
