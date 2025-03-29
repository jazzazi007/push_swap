/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnum_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:54:14 by moaljazz          #+#    #+#             */
/*   Updated: 2024/10/01 00:54:22 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexnum_upper(int num)
{
	char			*hex;
	int				i;
	unsigned int	n;

	n = (unsigned int)num;
	hex = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
		i += ft_hexnum_upper(n / 16);
	ft_p_putchar_fd(hex[n % 16], 1);
	i++;
	return (i);
}
