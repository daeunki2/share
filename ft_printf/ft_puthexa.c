/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:17:05 by daeunki2          #+#    #+#             */
/*   Updated: 2023/12/12 14:40:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexax(unsigned int n, char identifier)
{
	int		len;
	int		rest;
	char	alpha;

	len = 1;
	if (identifier == 'X')
		alpha = 'A';
	if (identifier == 'x')
		alpha = 'a';
	if (n >= 16)
	{
		len += ft_hexax(n / 16, identifier);
	}
	rest = n % 16;
	if (rest <= 9)
	{
		ft_putchar(rest + '0');
	}
	else
	{
		ft_putchar(rest - 10 + alpha);
	}
	return (len);
}
