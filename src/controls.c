/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:24 by prossi            #+#    #+#             */
/*   Updated: 2023/11/16 13:35:37 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	keyboard_w(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 13)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	ft_printf("→ Moves: %i\n°•Items: %i•˚\n", game->counter, game->collectables);
	return (1);
}

static int	keyboard_s(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 1)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("→ Moves: %i\n°•Items: %i•˚\n", game->counter, game->collectables);
	return (1);
}

static int	keyboard_a(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = game->x_axis;
	j = game->y_axis;
	if (movement == 0)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	ft_printf("→ Moves: %i\n°•Items: %i•˚\n", game->counter, game->collectables);
	return (1);
}

static int	keyboard_d(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 2)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("→ Moves: %i\n°•Items: %i•˚\n", game->counter, game->collectables);
	return (1);
}

int	controls_working(int command, t_game *game)
{
	int	works;

	if (command == 53)
		exit_point(game);
	if (command == 13)
		works = keyboard_w(game, command);
	if (command == 1)
		works = keyboard_s(game, command);
	if (command == 0)
		works = keyboard_a(game, command);
	if (command == 2)
		works = keyboard_d(game, command);
	if (works)
		adding_in_graphics(game);
	return (1);
}
