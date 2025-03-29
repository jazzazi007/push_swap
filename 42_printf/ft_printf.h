/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaljazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:38:59 by moaljazz          #+#    #+#             */
/*   Updated: 2024/09/30 20:39:03 by moaljazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_decm(int num);
int		ft_hexnum(unsigned int n);
int		ft_hexnum_upper(int num);
int		ft_udecm(unsigned int unum);
int		ft_ptr(unsigned long ptr);
char	*ft_p_itoa(int n);
void	ft_p_putchar_fd(char c, int fd);
int		ft_p_putstr_fd(char *s, int fd);
size_t	ft_p_strlen(const char *c);
int		ft_p_numlen(int n, int base);
#endif
