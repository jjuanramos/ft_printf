/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:54 by juramos           #+#    #+#             */
/*   Updated: 2023/11/27 13:42:53 by juramos          ###   ########.fr       */
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
	int		pos;

	pos = 0;
	value = va_arg(args, char *);
	while (value[pos])
	{
		write(1, &value[pos], 1);
		pos++;
	}
}

void	write_x(va_list args)
{
	unsigned int	value;

	value = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_base_fd(value, "0123456789abcdef", 1);
}

void	write_X(va_list args)
{
	unsigned int	value;

	value = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_base_fd(value, "0123456789ABCDEF", 1);
}

void	write_ptr(va_list args)
{
	unsigned int	value;

	value = (unsigned int)va_arg(args, unsigned int);
	if (!value)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		ft_putnbr_base_fd(value, "0123456789abcdef", 1);
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
			else if (format[pos] == 'x')
				write_x(args);
			else if (format[pos] == 'X')
				write_X(args);
			else if (format[pos] == 'p')
				write_ptr(args);
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
	char	c;

	c = 5;
	ft_printf("Hello %i, how you doing %c, %%, %u, %s, %x %p\n", 10010, 'b', 53, "bye juan", (-0xC), &c);
	printf("Hello %i, how you doing %c, %%, %u, %s, %x %p\n", 10010, 'b', 45, "bye juan", (-0xC), &c);
	return (0);
}
