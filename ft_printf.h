/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolaoual <yolaoual@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:22:13 by yolaoual          #+#    #+#             */
/*   Updated: 2024/12/05 09:22:27 by yolaoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_puthex(unsigned int n, char c);
int	ft_putint(int n);
int	ft_putptr(uintptr_t p);
int	ft_putunsigned_int(unsigned int n);
int	ft_putchar(int c);
int	ft_putstr(char *s);

#endif
