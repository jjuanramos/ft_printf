/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:54 by juramos           #+#    #+#             */
/*   Updated: 2023/11/21 13:51:44 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		value;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			*format++;
			if (*format == 'd')
			{
				value = va_arg(args, int);
				write(1, ft_itoa(value), ft_strlen(ft_itoa(value)));
			}
		}
		else
			write(1, format, 1);
		*format++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("Hello %d\n", 1);
	return (0);
}