/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_paring_the_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:09:15 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 14:30:23 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen_lines(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

static size_t	my_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	how_many_char(t_game *game, char *line, char *map_path)
{
	size_t	j;
	size_t	len;

	int (fd), i;
	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	len = ft_strlen_lines(line);
	while (line)
	{
		j = my_len(line);
		if (len != ft_strlen_lines(line))
			i++;
		free(line);
		line = get_next_line(fd);
	}
	if (j != len || i != 0)
	{
		free_map(game);
		return (0);
	}
	close(fd);
	return (1);
}

void	initialize_game(t_game *game)
{
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_count = 0;
	game->exit_count = 0;
	game->collectible_count = 0;
	game->count_moves = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->image_door = NULL;
	game->image_background = NULL;
	game->image_coin = NULL;
	game->image_player = NULL;
	game->exit.x = 0;
	game->exit.y = 0;
}
