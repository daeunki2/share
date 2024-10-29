/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:26:38 by daeunki2          #+#    #+#             */
/*   Updated: 2024/06/21 18:56:04 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char	*s);
int		ft_putstr(char	*str);
int		ft_putchar(char c);
int		ft_isformat(va_list arg, const char identifier);
int		ft_putnbr(int n);
int		ft_unsignednbr(unsigned int n);
int		ft_hexax(unsigned int n, char identifier);
int		ft_putpointer(void *ptr);
int		ft_printf(const char *format, ...);
int		ft_ptradress(unsigned long long int n);

#endif
