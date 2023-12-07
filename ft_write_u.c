/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:51:48 by juramos           #+#    #+#             */
/*   Updated: 2023/12/07 10:01:08 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_u(va_list args)
{
	unsigned int	value;
	size_t			i;

	value = (unsigned int)va_arg(args, int);
	i = putnbr_base_with_count_fd(value, "0123456789", 1);
	return (i);
}
