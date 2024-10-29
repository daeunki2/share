/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:19:47 by daeunki2          #+#    #+#             */
/*   Updated: 2023/12/12 11:50:55 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignednbr(unsigned int n)
{
	int	len;

	len = 1;
	if (n >= 10)
	{
		len += ft_unsignednbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	return (len);
}
