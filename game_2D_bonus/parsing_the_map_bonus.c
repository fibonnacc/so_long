/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:42:31 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/19 14:33:37 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	initialize_map(t_game *game)
{
	int	i;

	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	i = 0;
	while (i <= game->map_height)
		game->map[i++] = NULL;
	return (1);
}

int	open_and_initialize_map(t_game *game, char *map_path, int *fd)
{
	char	*line;

	line = NULL;
	if (!check_map_name(map_path))
		return (0);
	game->map_height = count_map_lines(map_path);
	if (game->map_height <= 0)
		return (0);
	if (!how_many_char(game, line, map_path))
		return (0);
	*fd = open(map_path, O_RDONLY);
	if (*fd < 0)
		return (0);
	if (!initialize_map(game))
	{
		close(*fd);
		return (0);
	}
	return (1);
}

int	read_and_process_map(t_game *game, int fd)
{
	int		y;
	char	*line;
	int		i;

	y = 0;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line(game, line, y, fd))
		{
			free(line);
			close(fd);
			i++;
		}
		line = get_next_line(fd);
		y++;
	}
	if (i != 0)
		return (free_map(game), 0);
	game->map[y] = NULL;
	close(fd);
	return (validate_map(game));
}

int	parse_map(t_game *game, char *map_path)
{
	int	fd;

	if (!open_and_initialize_map(game, map_path, &fd))
		return (0);
	return (read_and_process_map(game, fd));
}
