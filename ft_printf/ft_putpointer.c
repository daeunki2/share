/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:58:04 by daeunki2          #+#    #+#             */
/*   Updated: 2023/12/12 14:56:28 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	int					len;
	unsigned long long	ptr_adress;

	ptr_adress = (unsigned long long int)ptr;
	len = 0;
	if (ptr == NULL)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	len += ft_putstr("0x");
	len += ft_ptradress(ptr_adress);
	return (len);
}

int	ft_ptradress(unsigned long long int n)
{
	int		len;
	int		rest;

	len = 1;
	if (n >= 16)
	{
		len += ft_ptradress(n / 16);
	}
	rest = n % 16;
	if (rest <= 9)
	{
		ft_putchar(rest + '0');
	}
	else
	{
		ft_putchar(rest - 10 + 'a');
	}
	return (len);
}
