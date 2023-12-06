/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:52:28 by juramos           #+#    #+#             */
/*   Updated: 2023/12/06 12:31:42 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	putnbr_base_with_count_fd(int n, char *base, int fd)
{
	long	n_l;
	size_t	i;

	n_l = n;
	i = 0;
	if (n_l < 0)
	{
		i += write(fd, "-", 1);
		n_l *= -1;
	}
	if (n_l < (long)ft_strlen(base))
		i += write(fd, &base[n_l], 1);
	else
	{
		i += putnbr_base_with_count_fd(n_l / ft_strlen(base), base, fd);
		i += putnbr_base_with_count_fd(n_l % ft_strlen(base), base, fd);
	}
	return (i);
}

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
