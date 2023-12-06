/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:54 by juramos           #+#    #+#             */
/*   Updated: 2023/12/06 10:21:00 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	route_and_write(char type, va_list args)
{
	size_t	count;

	count = 0;
	if (type == 's')
		count += ft_write_s(args);
	else if (type == 'c')
		count += ft_write_c(args);
	// else if (type == 'd' || type == 'c')
	// 	count += ft_write_d(args);
	// else if (type == 'p')
	// 	count += ft_write_ptr(args);
	// else if (type == 'u')
	// 	count += ft_write_u(args);
	// else if (type == 'x')
	// 	count += ft_write_x(args);
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
	int		val_s_p;
	int		val_s_ft;
	int		val_c_p;
	int		val_c_ft;

	val_s_ft = ft_printf("Hello %s\n", "bye juan");
	val_s_p = printf("Hello %s\n", "bye juan");
	printf("val_s_p is %d, val_s_ft is %d.\n", val_s_p, val_s_ft);
	val_c_ft = ft_printf("Hello %c\n", 'c');
	val_c_p = printf("Hello %c\n", 'c');
	printf("val_c_p is %d, val_c_ft is %d.\n", val_c_p, val_c_ft);
	return (0);
}
