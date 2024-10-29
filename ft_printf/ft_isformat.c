/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:35:48 by daeunki2          #+#    #+#             */
/*   Updated: 2023/12/12 14:40:51 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isformat(va_list arg, const char identifier)
{
	int	len;

	len = 0;
	if (identifier == 'c')
			len += ft_putchar(va_arg(arg, int));
	if (identifier == 's')
			len += ft_putstr(va_arg(arg, char *));
	if (identifier == 'p')
			len += ft_putpointer(va_arg(arg, void *));
	if (identifier == 'd')
			len += ft_putnbr(va_arg(arg, int));
	if (identifier == 'i')
			len += ft_putnbr(va_arg(arg, int));
	if (identifier == 'u')
			len += ft_unsignednbr(va_arg(arg, unsigned int));
	if (identifier == 'x' || identifier == 'X')
			len += ft_hexax(va_arg(arg, unsigned int), identifier);
	if (identifier == '%')
			len += ft_putchar('%');
	return (len);
}
