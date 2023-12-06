/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:50:29 by juramos           #+#    #+#             */
/*   Updated: 2023/12/06 10:44:04 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putnbr_base_with_count_fd(int n, char *base, int fd)
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
	if (n_l < (long)ft_strlen(base)){
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


size_t	ft_write_d(va_list args)
{
	int		value;
	size_t	i;

	value = va_arg(args, int);
	i = putnbr_base_with_count_fd(value, "0123456789", 1);
	return (i);
}
