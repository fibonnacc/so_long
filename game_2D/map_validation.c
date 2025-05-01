/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:08:12 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/19 13:20:42 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_double(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_free_space(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->image_background, x
			* 64, y * 64);
	}
}

int	process_line(t_game *game, char *line, int y, int fd)
{
	if (y == 0)
		game->map_width = ft_strlen_lines(line);
	game->map[y] = ft_strdup(line);
	if (!game->map[y] || !parse_line(game, line, y))
	{
		close(fd);
		free_map(game);
		return (0);
	}
	game->map[y][game->map_width] = '\0';
	free(line);
	return (1);
}

int	check_map_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b' || filename[len
			- 2] != 'e' || filename[len - 1] != 'r')
		return (0);
	return (1);
}

int	parse_line(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x] != '\0' && line[x] != '\n')
	{
		if (!validate_map_chars(&line[x]))
			return (0);
		if (line[x] == 'P')
		{
			game->player_count++;
		}
		else if (line[x] == 'E')
			game->exit_count++;
		else if (line[x] == 'C')
			game->collectible_count++;
		game->map[y][x] = line[x];
		x++;
	}
	return (1);
}
