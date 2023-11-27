/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:54 by juramos           #+#    #+#             */
/*   Updated: 2023/11/27 11:22:12 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_d(va_list args)
{
	int	value;

	value = va_arg(args, int);
	ft_putnbr_fd(value, 1);
}

void	write_c(va_list args)
{
	char	value;

	value = (char)va_arg(args, int);
	write(1, &value, 1);
}

void	write_u(va_list args)
{
	unsigned int	value;

	value = (unsigned int)va_arg(args, int);
	ft_putnbr_fd(value, 1);
}

void	write_s(va_list args)
{
	char	*value;

	value = va_arg(args, char *);
	while (*value)
	{
		write(1, value, 1);
		*value++;
	}
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
			else if (format[pos] == 'u')
				write_u(args);
			else if (format[pos] == 's')
				write_s(args);
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
	ft_printf("Hello %i, how you doing %c, %%, %u, %s\n", 10010, 'b', 53, "bye juan");
	printf("Hello %i, how you doing %c, %%, %u, %s\n", 10010, 'b', 45, "bye juan");
	return (0);
}
