/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:51:48 by juramos           #+#    #+#             */
/*   Updated: 2023/12/06 12:32:09 by juramos          ###   ########.fr       */
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

size_t	ft_write_u(va_list args)
{
	unsigned int	value;
	size_t			i;

	value = (unsigned int)va_arg(args, int);
	i = putnbr_base_with_count_fd(value, "0123456789", 1);
	return (i);
}
