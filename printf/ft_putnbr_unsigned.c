/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:21:30 by helfatih          #+#    #+#             */
/*   Updated: 2024/11/21 15:21:32 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (n > 9)
	{
		count += ft_putnbr_unsigned(n / 10);
	}
	count += ft_putchar(n % 10 + 48);
	return (count);
}
