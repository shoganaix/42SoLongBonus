/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:28:55 by msoriano          #+#    #+#             */
/*   Updated: 2023/11/16 15:29:02 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_exit_accesible(char **map_copy, int i, int j)
{
	if (map_copy[i][j] == 'E')
		ft_printf("Exit is accesible\n");
	else if (map_copy[i + 1][j] != '1')
	{
		i ++;
		map_copy[i][j] = '1';
		check_exit_accesible(map_copy, i, j);
	}
	else if (map_copy[i][j + 1] != '1')
	{
		j ++;
		map_copy[i][j] = '1';
		check_exit_accesible(map_copy, i, j);
	}
	else if (map_copy[i - 1][j] != '1')
	{
		i --;
		map_copy[i][j] = '1';
		check_exit_accesible(map_copy, i, j);
	}
	else if (map_copy[i][j -1] != '1')
	{
		j --;
		map_copy[i][j] = '1';
		check_exit_accesible(map_copy, i, j);
	}
	else if (map_copy[i][j] != 'E')
		ft_printf("Error\nExit not accesible\n");
}

void	copy_map(t_game *game)
{
	char	**map_copy;
	int		line;
	int		i;
	int		p_coords[2];

	map_copy = (char **)malloc(sizeof(char *) * (ft_arraycount(game) + 1));
	line = 0;
	while (line < ft_arraycount(game))
	{
		i = 0;
		map_copy[line] = (char *)malloc(strlen (game->map[line]) + 1);
		while (game->map[line][i])
		{
			if (map_copy[line][i] == 'P')
			{
				p_coords[0] = i;
				p_coords[1] = line;
			}
			map_copy[line][i] = game->map[line][i];
			i++;
		}
		map_copy[line][i] = '\0';
		line++;
	}
	check_exit_accesible(map_copy, p_coords[0], p_coords[1]);
}

int	ft_arraycount(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}
