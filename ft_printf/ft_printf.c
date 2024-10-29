/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:46:09 by daeunki2          #+#    #+#             */
/*   Updated: 2023/12/12 16:34:56 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	arg;

	len = 0;
	i = 0;
	va_start (arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len = len + ft_isformat(arg, format[i + 1]);
			i++;
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
/*
#include <stdio.h>

int main(void)
{
	char			c;
	char			*s;
	char			*ns;
	void			*p;
	void			*np;
	int				d;
	int				i;
	unsigned int	u;
	int				x;

	c = 'a';
	s = "abcde";
	ns = 0;
	p = &d;
	np = 0;
	d = -2147483648;
	i = 2147483647;
	u = 4294967295;
	x = 123456789;

	ft_printf("<ft_printf>\n\n");
	ft_printf("c = %c\n", c);
	ft_printf(" len =%d\n\n",(ft_printf("%c", c)));
	ft_printf("s = %s\n", s);
	ft_printf(" len =%d\n\n",(ft_printf("%s", s)));
	ft_printf("s is NULL = %s\n", ns);
	ft_printf(" len =%d\n\n",(ft_printf("%s", ns)));
	ft_printf("p = %p\n", p);
	ft_printf(" len =%d\n\n",(ft_printf("%p", p)));
	ft_printf("p is NULL = %p\n", np);
	ft_printf(" len =%d\n\n",(ft_printf("%p", np)));
	ft_printf("d = %d\n", d);
	ft_printf(" len =%d\n\n",(ft_printf("%d", d)));
	ft_printf("i = %i\n", i);
	ft_printf(" len =%d\n\n",(ft_printf("%i", i)));
	ft_printf("u = %u\n", u);
	ft_printf(" len =%d\n\n",(ft_printf("%u", u)));
	ft_printf("X = %X", x);
	ft_printf(" len =%d\n\n",(ft_printf("%X", x)));
	ft_printf("x = %x\n", x);
	ft_printf(" len =%d\n\n",(ft_printf("%x", x)));
	ft_printf("%% = %%\n");
	ft_printf(" len =%d\n\n",(ft_printf("%%")));
	ft_printf("format is NULL, return %d\n", ft_printf(0));

	printf("----------------------------------------------------------------\n");

	printf("<printf>\n\n");
	printf("c = %c\n", c);
	printf(" len =%d\n\n",(printf("%c", c)));
	printf("s = %s\n", s);
	printf(" len =%d\n\n",(printf("%s", s)));
	printf("s is NULL = %s\n", ns);
	printf(" len =%d\n\n",(printf("%s", ns)));
	printf("p = %p\n", p);
	printf(" len =%d\n\n",(printf("%p", p)));
	printf("p is NULL = %p\n", np);
	printf(" len =%d\n\n",(printf("%p", np)));
	printf("d = %d\n", d);
	printf(" len =%d\n\n",(printf("%d", d)));
	printf("i = %i\n", i);
	printf(" len =%d\n\n",(printf("%i", i)));
	printf("u = %u\n", u);
	printf(" len =%d\n\n",(printf("%u", u)));
	printf("X = %X", x);
	printf(" len =%d\n\n",(printf("%X", x)));
	printf("x = %x\n", x);
	printf(" len =%d\n\n",(printf("%x", x)));
	printf("%% = %%\n");
	printf(" len =%d\n\n",(printf("%%")));
	printf("format is NULL, return %d\n", printf(0));
}
}
*/