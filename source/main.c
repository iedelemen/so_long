/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:56:29 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/18 14:45:56 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Printf/ft_printf.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

void	check_map_played(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'C')
		map->vc_count--;
	if (map->map[y][x] == 'E')
		map->ve_count--;
	if (map->v_map[y - 1][x] != '1')
	{
		map->v_map[y - 1][x] = '1';
		check_map_played(map, x, y - 1);
	}
	if (map->v_map[y + 1][x] != '1')
	{
		map->v_map[y + 1][x] = '1';
		check_map_played(map, x, y + 1);
	}
	if (map->v_map[y][x - 1] != '1')
	{
		map->v_map[y][x - 1] = '1';
		check_map_played(map, x - 1, y);
	}
	if (map->v_map[y][x + 1] != '1')
	{
		map->v_map[y][x + 1] = '1';
		check_map_played(map, x + 1, y);
	}
}

void	create_virtual_map(t_game *game)
{
	check_map_played(&game->map, game->p_x, game->p_y);
	if (game->map.vc_count != 0 || game->map.ve_count != 0)
		free_exit("Error\nC, P or E is not accessible\n", game);
}

void	data_init(t_game *game)
{
	game->map.width = 0;
	game->map.height = 0;
	game->map.e_count = 0;
	game->map.p_count = 0;
	game->map.c_count = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->map.vc_count = 0;
	game->map.ve_count = 0;
	game->map.moves = -1;
	game->map.map = NULL;
	game->map.v_map = NULL;
}

int	main(int arc, char **arv)
{
	t_game	game;

	if (arc == 2)
	{
		map_name_check(arv[1]);
		data_init(&game);
		read_map(arv[1], &game);
		player_xy(&game);
		map_equal(&game.map, &game);
		check_wall(&game.map, &game);
		create_virtual_map(&game);
		init_mlx(&game);
		render_map(&game);
		mlx_hook(game.win, 2, 0, keyboard, &game);
		mlx_hook(game.win, 17, 0, close_window, &game);
		mlx_loop_hook(game.mlx, put_xml, &game);
		mlx_loop(game.mlx);
	}
	else
	{
		ft_printf("Error\nNo file specified\n");
		exit (1);
	}
	free_exit ("Finish", &game);
}
