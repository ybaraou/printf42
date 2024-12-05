/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolaoual <yolaoual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:58:19 by yolaoual          #+#    #+#             */
/*   Updated: 2024/12/05 10:53:15 by yolaoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

static int	print_arg(va_list args, const char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count = ft_putptr(va_arg(args, uintptr_t));
	else if (c == 'd' || c == 'i')
		count = ft_putint(va_arg(args, int));
	else if (c == 'u')
		count = ft_putunsigned_int(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		count = ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (str == NULL || write(1,"",0) == -1)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += print_arg(args, str[i]);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
