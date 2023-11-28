/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:54 by juramos           #+#    #+#             */
/*   Updated: 2023/11/28 11:49:22 by juramos          ###   ########.fr       */
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

int	write_ptr(va_list args)
{
	unsigned int	value;
	int				count;

	value = (unsigned int)va_arg(args, unsigned int);
	if (!value)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		count = 2;
		write(1, "0x", 2);
		(value, "0123456789abcdef", 1);
	}
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		pos;
	int		count;

	pos = 0;
	count = 0;
	va_start(args, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			if (format[pos] == 'd' || format[pos] == 'i')
				count += write_d(args);
			else if (format[pos] == 'c')
				count += write_c(args);
			else if (format[pos] == 'u')
				count += write_u(args);
			else if (format[pos] == 's')
				count += write_s(args);
			else if (format[pos] == 'x')
				count += write_x(args);
			else if (format[pos] == 'X')
				count += write_X(args);
			else if (format[pos] == 'p')
				count += write_ptr(args);
			else
				count += write(1, "%", 1);
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
	int		val;

	c = 5;
	ft_printf("Hello %i, how you doing %c, %%, %u, %s, %x %p\n", 10010, 'b', 53, "bye juan", (-0xC), &c);
	val = printf("Hello %i, how you doing %c, %%, %u, %s, %x\n", 10010, 'b', 45, "bye juan", (-0xC));
	printf("val is %d.\n", val);
	return (0);
}
