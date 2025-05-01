/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlower_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:17:38 by helfatih          #+#    #+#             */
/*   Updated: 2024/11/21 15:17:42 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlower_hex(unsigned long long n, int count)
{
	count = 0;
	if (n >= 16)
		count += ft_putlower_hex((n / 16), count);
	if (n % 16 <= 9)
		count += ft_putchar(n % 16 + 48);
	else
		count += ft_putchar(n % 16 - 10 + 'a');
	return (count);
}
/*
int main() {
    ft_putlower_hex(999, 0);  // Example call to your function
    return 0;
}*/
