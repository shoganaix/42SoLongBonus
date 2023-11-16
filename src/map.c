/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:01 by prossi            #+#    #+#             */
/*   Updated: 2023/11/16 15:31:24 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_valid_width(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i + 1] != NULL)
	{
		if (width_of_map(game->map[i]) != width_of_map(game->map[i + 1]))
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_game *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!readmap)
			break ;
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	if (game->heightmap > 0)
		game->widthmap = width_of_map(game->map[0]);
	else
	{
		ft_printf("Error\nFile is empty\n");
		return (0);
	}
	if (!check_valid_width(game))
		return (0);
	return (1);
}

int	right_move(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\n                ☆☆☆Congratulations!☆☆☆\n");
		ft_printf("→ FINAL MOVES: %i\n", game->counter + 1);
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}
