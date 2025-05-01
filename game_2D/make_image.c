/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:37:46 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 14:25:04 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->image_walls,
					j * 64, i * 64);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->image_player, j * 64, i * 64);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->image_background, j * 64, i * 64);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->image_coin,
					j * 64, i * 64);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->image_door,
					j * 64, i * 64);
			j++;
		}
	}
}

void	make_image(t_game *game)
{
	int	img_height;
	int	img_width;

	game->image_walls = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&img_width, &img_height);
	game->image_coin = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm",
			&img_width, &img_height);
	game->image_player = mlx_xpm_file_to_image(game->mlx,
			"./textures/warrior.xpm", &img_width, &img_height);
	game->image_door = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm",
			&img_width, &img_height);
	game->image_background = mlx_xpm_file_to_image(game->mlx,
			"./textures/background.xpm", &img_width, &img_height);
	if (!game->image_background || !game->image_door || !game->image_player
		|| !game->image_coin || !game->image_walls)
	{
		clean_all(game);
		exit(0);
	}
}
