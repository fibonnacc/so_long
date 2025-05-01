/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:37:46 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 20:17:35 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	destroy_image(t_game *game)
{
	if (!game->win || !game->mlx)
		return ;
	if (game->image_player)
		mlx_destroy_image(game->mlx, game->image_player);
	if (game->image_door)
		mlx_destroy_image(game->mlx, game->image_door);
	if (game->image_coin)
		mlx_destroy_image(game->mlx, game->image_coin);
	if (game->image_background)
		mlx_destroy_image(game->mlx, game->image_background);
	if (game->image_walls)
		mlx_destroy_image(game->mlx, game->image_walls);
	if (game->image_enemy)
		mlx_destroy_image(game->mlx, game->image_enemy);
	if (game->image_move)
		mlx_destroy_image(game->mlx, game->image_move);
}

void	clean_all(t_game *game)
{
	if (!game)
		return ;
	destroy_image(game);
	if (game->win && game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	free_map(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

int	handle_esc(int keypress, t_game *game)
{
	if (keypress == 65307)
	{
		clean_all(game);
		exit(1);
	}
	else if (keypress == 65362)
		move_up(game);
	else if (keypress == 65364)
		move_down(game);
	else if (keypress == 65361)
		move_left(game);
	else if (keypress == 65363)
		move_right(game);
	if (!check_exit(game))
		exit(0);
	return (0);
}

void	image_process(t_game *game)
{
	int (i), j;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == '1')
				draw_image(game, game->image_walls, j, i);
			else if (game->map[i][j] == 'P')
				draw_image(game, game->image_player, j, i);
			else if (game->map[i][j] == '0')
				draw_image(game, game->image_background, j, i);
			else if (game->map[i][j] == 'C')
				draw_image(game, game->image_coin, j, i);
			else if (game->map[i][j] == 'E')
				draw_image(game, game->image_door, j, i);
			else if (game->map[i][j] == 'K')
				draw_image(game, game->image_enemy, j, i);
		}
	}
}

void	make_image(t_game *game)
{
	int	img_height;
	int	img_width;

	game->image_walls = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&img_width, &img_height);
	game->image_enemy = mlx_xpm_file_to_image(game->mlx, "./textures/enemy.xpm",
			&img_width, &img_height);
	game->image_coin = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm",
			&img_width, &img_height);
	game->image_player = mlx_xpm_file_to_image(game->mlx,
			"./textures/warrior.xpm", &img_width, &img_height);
	game->image_door = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm",
			&img_width, &img_height);
	game->image_background = mlx_xpm_file_to_image(game->mlx,
			"./textures/background.xpm", &img_width, &img_height);
	game->image_move = mlx_xpm_file_to_image(game->mlx, "./textures/black.xpm",
			&img_width, &img_height);
	if (!game->image_background || !game->image_door || !game->image_player
		|| !game->image_coin || !game->image_walls || !game->image_enemy)
	{
		clean_all(game);
		exit(0);
	}
}
