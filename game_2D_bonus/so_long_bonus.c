/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:31:35 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 18:14:36 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	validate_map_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E'
			&& line[i] != 'C' && line[i] != 'K')
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int (y), x;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (y == 0 || y == game->map_height - 1)
			{
				if (game->map[y][x] != '1')
					return (0);
			}
			else if (x == 0 || x == game->map_width - 1)
			{
				if (game->map[y][x] != '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (game->player_count != 1)
		return (0);
	if (game->exit_count != 1)
		return (0);
	if (game->collectible_count < 1)
		return (0);
	if (!check_walls(game))
		return (0);
	return (1);
}

int	count_map_lines(char *map_path)
{
	int		fd;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		initialize_game(&game);
		if (!parse_map(&game, av[1]))
		{
			free_map(&game);
			write(2, "Error :\n", 8);
			write(2, "Map parsing Faild.\n", 19);
			return (1);
		}
		start_flood_fill(&game);
		creat_envirement(&game);
		free_map(&game);
		return (0);
	}
}
