/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:03 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/20 16:11:19 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	if (game->win)
		clean_all(game);
	exit(1);
	return (0);
}

void	creat_envirements(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * 64, game->map_height
			* 64, "So Long Animation");
	if (!game->win)
		exit(0);
	make_image(game);
	image_process(game);
	mlx_hook(game->win, 2, 1L, handle_esc, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

int	check_exit(t_game *game)
{
	if (game->player.y == game->exit.y && game->player.x == game->exit.x
		&& game->collectible_count == 0)
	{
		clean_all(game);
		game->count_moves++;
		ft_printf("player moves : %d\n", game->count_moves);
		ft_printf("🎉 Congratulations! You won the game! 🏆\n");
		return (0);
	}
	return (1);
}
