/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:56:44 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/18 14:44:34 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "../Libft/libft.h"
#include "../GetNextLine/get_next_line.h"
#include <unistd.h>
#include "../Printf/ft_printf.h"

char	*strappend(char **str, char *str2)
{
	char	*old;

	old = *str;
	*str = ft_strjoin(old, str2);
	free(old);
	return (*str);
}

char	*read_file(char *path, t_game *game)
{
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile does not exist!\n");
		exit (1);
	}
	tmp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		nl_check(line[0], game);
		strappend(&tmp, line);
		free(line);
	}
	close(fd);
	return (tmp);
}

void	read_map(char *path, t_game *game)
{
	char	*map;

	map = read_file(path, game);
	game->map.map = ft_split(map, '\n');
	game->map.v_map = ft_split(map, '\n');
	game->map.height = 0;
	while (game->map.map[game->map.height])
		game->map.height++;
	game->map.width = ft_strlen(game->map.map[0]);
	free (map);
	validate_map(game);
}

void	validate_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.map[i][j] == 'E')
				game->map.e_count++;
			if (game->map.map[i][j] == 'P')
				game->map.p_count++;
			if (game->map.map[i][j] == 'C')
				game->map.c_count++;
		}
	}
	game->map.vc_count += game->map.c_count;
	game->map.ve_count += game->map.e_count;
	if (game->map.e_count != 1 || game->map.p_count != 1
		|| game->map.c_count < 1)
		free_exit("Error\nSomething missing!\n", game);
}

void	player_xy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
