/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:54 by juramos           #+#    #+#             */
/*   Updated: 2023/11/27 11:07:49 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_d(va_list args)
{
	int	value;

	value = va_arg(args, int);
	write(1, ft_itoa(value), ft_strlen(ft_itoa(value)));
}

void	write_c(va_list args)
{
	char	value;

	value = (char)va_arg(args, int);
	write(1, &value, 1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		pos;

	pos = 0;
	va_start(args, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			if (format[pos] == 'd' || format[pos] == 'i')
				write_d(args);
			else if (format[pos] == 'c')
				write_c(args);
			else
				write(1, "%", 1);
		}
		else
			write(1, &format[pos], 1);
		pos++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("Hello %i, how you doing %c, %%\n", -1, 'b');
	printf("Hello %i, how you doing %c, %%\n", -1, 'b');
	return (0);
}
