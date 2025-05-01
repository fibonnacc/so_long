/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfatih <helfatih@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:20:27 by helfatih          #+#    #+#             */
/*   Updated: 2024/11/23 16:20:30 by helfatih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_putlower_hex(unsigned long long n, int count);
int		ft_putupper_hex(unsigned long long n, int count);
int		ft_putnbr_unsigned(unsigned int n);
char	*ft_strchr(const char *str, int c);
int		ft_putchar(char c);
int		ft_pointer(void *p, int count);
#endif
