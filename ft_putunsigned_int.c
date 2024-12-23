/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolaoual <yolaoual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:23:40 by yolaoual          #+#    #+#             */
/*   Updated: 2024/12/05 09:44:30 by yolaoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_lenu(unsigned int c)
{
	int	len;

	len = 1;
	while (c > 9)
	{
		c /= 10;
		len++;
	}
	return (len);
}

static char	*convert_to_charu(unsigned int num)
{
	int		len;
	char	*res;

	len = get_lenu(num);
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
	return (res);
}

int	ft_putunsigned_int(unsigned int n)
{
	char	*s;
	int		count;

	s = convert_to_charu(n);
	count = ft_putstr(s);
	free(s);
	return (count);
}
