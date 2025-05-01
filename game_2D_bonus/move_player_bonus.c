/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:00:14 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 20:17:19 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_player(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->image_player, x
			* 64, y * 64);
		image_move(game);
		game->count_moves++;
	}
}

void	move_up(t_game *game)
{
	int	new_y;

	new_y = game->player.y - 1;
	if (new_y > 0 && game->map[new_y][game->player.x] != '1')
	{
		if (game->map[new_y][game->player.x] == 'C')
			game->collectible_count--;
		if (game->map[new_y][game->player.x] == 'K')
		{
			clean_all(game);
			ft_printf("💥 Oops! You touched the enemy! 😱 \n");
			exit(0);
		}
		game->map[new_y][game->player.x] = 'P';
		game->map[game->player.y][game->player.x] = '0';
		print_free_space(game, game->player.x, game->player.y);
		game->player.y = new_y;
		if ((game->player.y != game->exit.y || game->player.x != game->exit.x)
			&& game->collectible_count != 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->image_door,
				game->exit.x * 64, game->exit.y * 64);
		}
		print_player(game, game->player.x, new_y);
	}
}

void	move_down(t_game *game)
{
	int	new_y;

	new_y = game->player.y + 1;
	if (new_y > 0 && game->map[new_y][game->player.x] != '1')
	{
		if (game->map[new_y][game->player.x] == 'C')
			game->collectible_count--;
		if (game->map[new_y][game->player.x] == 'K')
		{
			clean_all(game);
			ft_printf("💥 Oops! You touched the enemy! 😱 \n");
			exit(0);
		}
		game->map[new_y][game->player.x] = 'P';
		game->map[game->player.y][game->player.x] = '0';
		print_free_space(game, game->player.x, game->player.y);
		game->player.y = new_y;
		if ((game->player.y != game->exit.y || game->player.x != game->exit.x)
			&& game->collectible_count != 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->image_door,
				game->exit.x * 64, game->exit.y * 64);
		}
		print_player(game, game->player.x, new_y);
	}
}

void	move_left(t_game *game)
{
	int	new_x;

	new_x = game->player.x - 1;
	if (new_x > 0 && game->map[game->player.y][new_x] != '1')
	{
		if (game->map[game->player.y][new_x] == 'C')
			game->collectible_count--;
		if (game->map[game->player.y][new_x] == 'K')
		{
			clean_all(game);
			ft_printf("💥 Oops! You touched the enemy! 😱 \n");
			exit(0);
		}
		game->map[game->player.y][new_x] = 'P';
		game->map[game->player.y][game->player.x] = '0';
		print_free_space(game, game->player.x, game->player.y);
		game->player.x = new_x;
		if ((game->player.y != game->exit.y || game->player.x != game->exit.x)
			&& game->collectible_count != 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->image_door,
				game->exit.x * 64, game->exit.y * 64);
		}
		print_player(game, new_x, game->player.y);
	}
}

void	move_right(t_game *game)
{
	int	new_x;

	new_x = game->player.x + 1;
	if (new_x > 0 && game->map[game->player.y][new_x] != '1')
	{
		if (game->map[game->player.y][new_x] == 'C')
			game->collectible_count--;
		if (game->map[game->player.y][new_x] == 'K')
		{
			clean_all(game);
			ft_printf("💥 Oops! You touched the enemy! 😱 \n");
			exit(0);
		}
		game->map[game->player.y][new_x] = 'P';
		game->map[game->player.y][game->player.x] = '0';
		print_free_space(game, game->player.x, game->player.y);
		game->player.x = new_x;
		if ((game->player.y != game->exit.y || game->player.x != game->exit.x)
			&& game->collectible_count != 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->image_door,
				game->exit.x * 64, game->exit.y * 64);
		}
		print_player(game, new_x, game->player.y);
	}
}
