/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:54 by juramos           #+#    #+#             */
/*   Updated: 2023/11/28 12:31:42 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	route_and_write(char type, va_list args)
{
	size_t	count;

	count = 0;
	if (type == 's')
		count += ft_write_s(args);
	else
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	pos;
	size_t	count;

	pos = 0;
	count = 0;
	va_start(args, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			count += route_and_write(format[pos], args);
		}
		else
			count += write(1, &format[pos], 1);
		pos++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	c;
	int		val_p;
	int		val_ft;

	val_ft = ft_printf("Hello %s\n", "bye juan");
	val_p = printf("Hello %s\n", "bye juan");
	printf("val_p is %d, val_ft is %d.\n", val_p, val_ft);
	return (0);
}
