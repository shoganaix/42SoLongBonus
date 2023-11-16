/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:49:02 by prossi            #+#    #+#             */
/*   Updated: 2023/11/16 15:27:27 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_errors(t_game *game)
{
	if_walls(game);
	character_valid(game);
	copy_map(game);
}

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

static bool	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(&argv[1], '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (false);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !(is_ber_file(argv[1])))
	{
		ft_printf("Error!\nArguments or file issue\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!map_reading(&game, argv))
		return (0);
	check_errors(&game);

	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 64),
			(game.heightmap * 64), "solong");
	place_images_in_game(&game);
	if (place_images_in_game(&game) == 0)
	{
		ft_printf("Error!\nMissing Graphics\n");
		return (0);
	}
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
