/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:52:22 by helfatih          #+#    #+#             */
/*   Updated: 2024/11/21 20:52:25 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *p, int count)
{
	unsigned long long	var;

	var = (unsigned long long)p;
	if (var == 0)
	{
		return (ft_putstr("(nil)"));
	}
	write (1, "0x", 2);
	count += 2;
	count += ft_putlower_hex(var, count);
	return (count);
}
