/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:39:21 by moaljazz          #+#    #+#             */
/*   Updated: 2024/09/30 20:39:23 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	states(const char *str, int i, va_list ptr)
{
	if (str[i] == 'i' || str[i] == 'd')
		return (ft_decm(va_arg(ptr, int)));
	else if (str[i] == 'c')
	{
		ft_p_putchar_fd((char)va_arg(ptr, int), 1);
		return (1);
	}
	else if (str[i] == 's')
		return (ft_p_putstr_fd(va_arg(ptr, char *), 1));
	else if (str[i] == 'x')
		return (ft_hexnum(va_arg(ptr, unsigned long)));
	else if (str[i] == 'X')
		return (ft_hexnum_upper(va_arg(ptr, unsigned long)));
	else if (str[i] == '%')
	{
		ft_p_putchar_fd('%', 1);
		return (1);
	}
	else if (str[i] == 'u')
		return (ft_udecm((unsigned int)va_arg(ptr, int)));
	else if (str[i] == 'p')
		return (ft_ptr(va_arg(ptr, unsigned long)));
	return (0);
}

static int	isprintabe(const char *str, int i)
{
	if (str[i + 1] == 'i' || str[i + 1] == 'd' || str[i + 1] == 'c'
		|| str[i + 1] == 's' || str[i + 1] == 'x' || str[i + 1] == 'X'
		|| str[i + 1] == 'u' || str[i + 1] == 'p' || str[i + 1] == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		counter;
	int		i;

	va_start(ptr, str);
	counter = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			counter += states(str, i += isprintabe(str, i), ptr);
		else
		{
			ft_p_putchar_fd(str[i], 1);
			counter++;
		}
		i++;
	}
	va_end(ptr);
	return (counter);
}
