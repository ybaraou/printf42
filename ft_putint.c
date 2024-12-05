/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolaoual <yolaoual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:23:10 by yolaoual          #+#    #+#             */
/*   Updated: 2024/12/05 09:43:19 by yolaoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(long int num, int is_neg)
{
	int			len;
	long int	c;

	len = 1;
	c = num;
	if (is_neg && num != 0)
		len++;
	while (c > 9)
	{
		c /= 10;
		len++;
	}
	return (len);
}

static char	*convert_to_char(long int num, int is_neg)
{
	int		len;
	char	*res;

	len = get_len(num, is_neg);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = num % 10 + '0';
		num /= 10;
		len--;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}

static char	*ft_itoa(int n)
{
	long int	num;
	int			is_neg;
	char		*res;

	is_neg = 0;
	num = (long int)n;
	if (n < 0)
	{
		num = -1 * num;
		is_neg = 1;
	}
	res = convert_to_char(num, is_neg);
	if (!res)
		return (NULL);
	return (res);
}

int	ft_putint(int n)
{
	char *s;
	int count;

	s = ft_itoa(n);
	count = ft_putstr(s);
	free(s);
	return (count);
}
