/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:34:52 by moaljazz          #+#    #+#             */
/*   Updated: 2024/09/30 20:34:55 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	ft_hexptr(unsigned long n)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		i += ft_hexptr(n / 16);
	ft_p_putchar_fd(hex[n % 16], 1);
	i++;
	return (i);
}

int	ft_ptr(unsigned long ptr)
{
	int	i;

	if (!ptr)
	{
		ft_p_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_p_putstr_fd("0x", 1);
	i = ft_hexptr(ptr);
	return (i + 2);
}
