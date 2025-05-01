/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:25:25 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 14:34:15 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	t_position	player;
	t_position	exit;
	int			player_count;
	int			exit_count;
	int			collectible_count;
	void		*mlx;
	void		*win;
	void		*image_player;
	void		*image_door;
	void		*image_background;
	void		*image_walls;
	void		*image_coin;
	int			count_moves;
}				t_game;

size_t			ft_strlen_lines(const char *str);
int				validate_map_chars(char *line);
int				check_walls(t_game *game);
void			initialize_game(t_game *game);
int				how_many_char(t_game *game, char *line, char *map_path);
int				validate_map(t_game *game);
int				count_map_lines(char *map_path);
int				parse_line(t_game *game, char *line, int y);
int				parse_map(t_game *game, char *map_path);
int				check_map_name(char *filename);
void			free_map(t_game *game);
int				open_and_initialize_map(t_game *game, char *map_path, int *fd);
int				process_line(t_game *game, char *line, int y, int fd);
int				initialize_map(t_game *game);
int				read_and_process_map(t_game *game, int fd);
char			**copy_map(t_game *game);
void			free_double(char **arr);
void			flood_fill(t_game *game, char **arr, int x, int y);
void			give_coord(t_game *game);
void			start_flood_fill(t_game *game);
void			check_element(t_game *game, char **arr);
void			creat_envirements(t_game *game);
void			make_image(t_game *game);
void			image_process(t_game *game);
int				handle_esc(int keypress, t_game *game);
int				close_window(t_game *game);
void			clean_all(t_game *game);
void			destroy_image(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			move_down(t_game *game);
void			move_up(t_game *game);
void			print_player(t_game *game, int x, int y);
void			print_free_space(t_game *game, int x, int y);
int				check_exit(t_game *game);

#endif
