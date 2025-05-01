/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:12:06 by helfatih          #+#    #+#             */
/*   Updated: 2025/02/22 19:25:19 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	count_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	*ft_fix(int n, char *result, int i)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			result[0] = '-';
			result[1] = '2';
			n = 147483648;
		}
		else
		{
			result[0] = '-';
			n = -n;
		}
	}
	while (n > 0)
	{
		result[--i] = n % 10 + 48;
		n /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	i = count_len(n);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (n == 0)
	{
		result[0] = '0';
	}
	else
	{
		ft_fix(n, result, i);
	}
	return (result);
}

void	draw_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 64, y * 64);
}
