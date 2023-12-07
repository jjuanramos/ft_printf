/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:52:28 by juramos           #+#    #+#             */
/*   Updated: 2023/12/07 10:01:16 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_x(va_list args)
{
	unsigned int	value;
	size_t			count;

	count = 0;
	value = (unsigned int)va_arg(args, unsigned int);
	count += putnbr_base_with_count_fd(value, "0123456789abcdef", 1);
	return (count);
}

size_t	ft_write_x_upper(va_list args)
{
	unsigned int	value;
	size_t			count;

	count = 0;
	value = (unsigned int)va_arg(args, unsigned int);
	count += putnbr_base_with_count_fd(value, "0123456789ABCDEF", 1);
	return (count);
}
