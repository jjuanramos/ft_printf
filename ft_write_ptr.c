/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:21 by juramos           #+#    #+#             */
/*   Updated: 2023/12/06 12:25:49 by juramos          ###   ########.fr       */
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
		write(fd, "-", 1);
		n_l *= -1;
		i++;
	}
	if (n_l < (long)ft_strlen(base))
	{
		write(fd, &base[n_l], 1);
		i++;
	}
	else
	{
		i += putnbr_base_with_count_fd(n_l / ft_strlen(base), base, fd);
		i += putnbr_base_with_count_fd(n_l % ft_strlen(base), base, fd);
	}
	return (i);
}

size_t	ft_write_ptr(va_list args)
{
	unsigned int	value;
	int				count;

	value = (unsigned int)va_arg(args, unsigned int);
	if (!value)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
	{
		count = 2;
		write(1, "0x", 2);
		count += putnbr_base_with_count_fd(value, "0123456789abcdef", 1);
	}
	return (count);
}
