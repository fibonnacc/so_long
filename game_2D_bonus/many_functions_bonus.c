/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:05:03 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 20:20:40 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	close_window(t_game *game)
{
	if (game->win)
		clean_all(game);
	exit(1);
	return (0);
}

int	image_move(t_game *game)
{
	char	*str_move;
	char	*join;

	str_move = ft_itoa(game->count_moves);
	if (!str_move)
		return (0);
	join = ft_strjoin("the moves : ", str_move);
	free(str_move);
	if (!join)
	{
		clean_all(game);
		exit(0);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image_move, 0 * 64, 0
		* 64);
	mlx_string_put(game->mlx, game->win, 20, 15, 0xFFFFFF, join);
	free(join);
	return (1);
}

int	check_exit(t_game *game)
{
	if (game->player.y == game->exit.y && game->player.x == game->exit.x
		&& game->collectible_count == 0)
	{
		clean_all(game);
		ft_printf("🎉 Congratulations! You won the game! 🏆\n");
		return (0);
	}
	return (1);
}

void	creat_envirement(t_game *game)
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
