/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:56:41 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/16 17:21:41 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 100
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_map
{
	char	**map;
	char	**v_map;
	int		width;
	int		height;
	int		moves;
	int		e_count;
	int		p_count;
	int		c_count;
	int		vc_count;
	int		ve_count;
}	t_map;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	void	*collectibles;
	void	*exit;
	void	*wall;
	void	*bground;
	void	*player;
	int		p_x;
	int		p_y;
}	t_game;

//main.c
void	data_init(t_game *game);
void	map_check(t_map *map);
//check.c
void	map_name_check(char *map_name);
void	file_check(char *map_name);
void	nl_check(char line, t_game *game);
void	map_equal(t_map *map, t_game *game);
void	check_characters(char *tmp);

//init_mlx.c
void	init_mlx(t_game *game);
void	render_map(t_game *game);
int		mlx_exit(t_game *game, char *str);
void	free_exit(char *str, t_game *game);
void	free_map(char **map);
//playing.c
int		keyboard(int keycode, t_game *game);
int		close_window(t_game *game);
int		put_xml(t_game *game);
void	check_wall(t_map *map, t_game *game);
//validation.c
void	read_map(char *map_name, t_game *game);
void	validate_map(t_game *game);
void	player_xy(t_game *game);

#endif
