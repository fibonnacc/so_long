/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:22:24 by helfatih          #+#    #+#             */
/*   Updated: 2024/11/21 15:56:27 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hi(const char c, va_list args)
{
	int	i;

	i = 0;
	if (c == '%')
		i += ft_putchar('%');
	else if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_putnbr_unsigned((unsigned)va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_putlower_hex((unsigned)(va_arg(args, int)), i);
	else if (c == 'X')
		i += ft_putupper_hex((unsigned)(va_arg(args, int)), i);
	else if (c == 'p')
	{
		i += ft_pointer(va_arg(args, void *), i);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	char	*hi;

	i = 0;
	if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	va_start(args, format);
	hi = "dicuxsXp%";
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr(hi, format[i + 1]))
		{
			count += ft_printf_hi(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int main()
{
	//char str[] = "%";
	//int x = ft_printf("%p", str);
	//int v = printf("%p", str);
	int x = ft_printf("%");
	ft_printf("%d\n", x);
}*/
