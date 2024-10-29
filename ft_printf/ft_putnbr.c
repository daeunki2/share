/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:21:54 by daeunki2          #+#    #+#             */
/*   Updated: 2023/12/12 14:36:04 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long long	nbr;
	int			len;

	len = 1;
	nbr = (long long)n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		len++;
	}
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + '0');
	return (len);
}
