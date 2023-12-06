/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:21 by juramos           #+#    #+#             */
/*   Updated: 2023/12/06 10:22:09 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_ptr(va_list args)
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
		ft_putnbr_base_fd(value, "0123456789abcdef", 1);
	}
}
