/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:56:26 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/17 13:02:01 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include "../Printf/ft_printf.h"
#include <stdlib.h>

void	init_mlx(t_game *game)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * PIXEL,
			game->map.height * PIXEL, "so_long");
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&y, &x);
	game->collectibles = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			&y, &x);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &y, &x);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &y, &x);
	game->bground = mlx_xpm_file_to_image(game->mlx, "textures/bground.xpm",
			&y, &x);
	if (!game->player || !game->collectibles || !game->exit
		|| !game->wall || !game->bground || !game->mlx || !game->win)
		mlx_exit(game, "Error\nTextures not loaded");
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(game->mlx, game->win);
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall, j * PIXEL, i * PIXEL);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->bground, j * PIXEL, i * PIXEL);
			if (game->map.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit, j * PIXEL, i * PIXEL);
			else if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectibles, j * PIXEL, i * PIXEL);
		}
	}
}

int	mlx_exit(t_game *game, char *str)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectibles)
		mlx_destroy_image(game->mlx, game->collectibles);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->bground)
		mlx_destroy_image(game->mlx, game->bground);
	return (free_exit(str, game), 0);
}

void	free_exit(char *str, t_game *game)
{
	if (game->map.map)
		free_map(game->map.map);
	if (game->map.v_map)
		free_map(game->map.v_map);
	ft_printf("%s", str);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}
