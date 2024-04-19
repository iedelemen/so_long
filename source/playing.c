/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:56:32 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/17 13:48:29 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Printf/ft_printf.h"
#include "../minilibx/mlx.h"

int	keyboard(int keycode, t_game *game)
{
	if (keycode == 53)
		mlx_exit(game, "Exit\n");
	else if (keycode == 13 && game->map.map[game->p_y - 1][game->p_x] != '1')
		game->p_y -= 1;
	else if (keycode == 1 && game->map.map[game->p_y + 1][game->p_x] != '1')
		game->p_y += 1;
	else if (keycode == 0 && game->map.map[game->p_y][game->p_x - 1] != '1')
		game->p_x -= 1;
	else if (keycode == 2 && game->map.map[game->p_y][game->p_x + 1] != '1')
		game->p_x += 1;
	else
		return (0);
	ft_printf("Moves:%d\n", ++game->map.moves);
	if (game->map.map[game->p_y][game->p_x] == 'C')
	{
		game->map.c_count--;
		game->map.map[game->p_y][game->p_x] = '0';
	}
	if (game->map.map[game->p_y][game->p_x] == 'E' && game->map.c_count == 0)
		mlx_exit(game, "Finish You Win!\n");
	return (0);
}

int	close_window(t_game *game)
{
	mlx_exit(game, "Exit\n");
	return (0);
}

int	put_xml(t_game *game)
{
	render_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		game->p_x * PIXEL, game->p_y * PIXEL);
	return (0);
}

void	check_wall(t_map *map, t_game *game)
{
	int		i;

	i = -1;
	while (++i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			free_exit ("Error\nMap is invalid! Wall is not closed!\n", game);
	}
	i = -1;
	while (++i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			free_exit ("Error\nMap is invalid! Wall is not closed!\n", game);
	}
}
