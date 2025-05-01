/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlupper_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:20:40 by helfatih          #+#    #+#             */
/*   Updated: 2024/11/21 15:20:44 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putupper_hex(unsigned long long n, int count)
{
	count = 0;
	if (n >= 16)
		count += ft_putupper_hex(n / 16, count);
	if (n % 16 <= 9)
		count += ft_putchar(n % 16 + 48);
	else
		count += ft_putchar(n % 16 - 10 + 'A');
	return (count);
}
