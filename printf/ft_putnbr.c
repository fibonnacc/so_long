/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:54:47 by helfatih          #+#    #+#             */
/*   Updated: 2024/11/21 11:54:59 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			count += ft_putstr("-2147483648");
			return (count);
		}
		else
		{
			count += ft_putchar('-');
			n = -n;
		}
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	count += ft_putchar((n % 10) + '0');
	return (count);
}
/*
#include <stdio.h>
int	main()
{
	int x;
	x  = ft_putnbr(534);
	ft_printf("%d",x);
}*/
