/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:44:05 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 19:22:45 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	give_coord(t_game *game)
{
	int (i), j;
	i = -1;
	while (++i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit.x = j;
				game->exit.y = i;
			}
			j++;
		}
	}
}

void	flood_fill(t_game *game, char **arr, int x, int y)
{
	if (y < 0 || y >= game->map_height || x < 0 || x >= game->map_width)
		return ;
	if (arr[y][x] == '1' || arr[y][x] == 'F')
		return ;
	arr[y][x] = 'F';
	flood_fill(game, arr, x, y + 1);
	flood_fill(game, arr, x, y - 1);
	flood_fill(game, arr, x + 1, y);
	flood_fill(game, arr, x - 1, y);
}

char	**copy_map(t_game *game)
{
	char	**arr;

	int (i), j;
	arr = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		arr[i] = malloc(sizeof(char) * (game->map_width + 1));
		if (!arr[i])
			return (free_double(arr), NULL);
		j = 0;
		while (j < game->map_width)
		{
			arr[i][j] = game->map[i][j];
			j++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	check_element(t_game *game, char **arr)
{
	int (i), j;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'C' || arr[i][j] == 'E')
			{
				free_map(game);
				free_double(arr);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	start_flood_fill(t_game *game)
{
	char	**arr;

	arr = copy_map(game);
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	give_coord(game);
	flood_fill(game, arr, game->player.x, game->player.y);
	check_element(game, arr);
	free_double(arr);
}
