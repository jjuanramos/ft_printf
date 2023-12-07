/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:50:29 by juramos           #+#    #+#             */
/*   Updated: 2023/12/07 10:00:58 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_d(va_list args)
{
	int		value;
	size_t	i;

	value = va_arg(args, int);
	i = putnbr_base_with_count_fd(value, "0123456789", 1);
	return (i);
}
