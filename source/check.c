/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:56:21 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/18 12:55:27 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "../Printf/ft_printf.h"
#include <stdlib.h>
#include "../Libft/libft.h"
#include <unistd.h>

void	map_name_check(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i] != '\0')
		i++;
	if (map_name[i - 1] == 'r' && map_name[i - 2] == 'e'
		&& map_name[i - 3] == 'b' && map_name[i - 4] == '.')
		file_check(map_name);
	else
	{
		ft_printf("Error\nMap name is incorrect!\n");
		exit (1);
	}
}

void	check_map_characters(t_map *map, t_game *game)
{
	int		i;
	int		k;

	i = 0;
	while (i < map->height)
	{
		k = 0;
		while (k < map->width)
		{
			if (map->map[i][k] != '0' && map->map[i][k] != '1' && map->map[i][k]
				!= 'P' && map->map[i][k] != 'E' && map->map[i][k] != 'C')
				free_exit("Error\nMap contains invalid characters!\n", game);
			k++;
		}
		i++;
	}
}

void	map_equal(t_map *map, t_game *game)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		if (map->width != (int)ft_strlen(map->map[i]))
			free_exit("Error\nMap is not rectangular!\n", game);
		i++;
	}
	check_map_characters(map, game);
}

void	file_check(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile does not exist!\n");
		close(fd);
		exit (1);
	}
	close(fd);
}

void	nl_check(char line, t_game *game)
{
	if (line == '\n')
		free_exit ("Error\nEmpty Line In Map\n", game);
}
