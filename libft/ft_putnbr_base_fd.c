/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:13:26 by juramos           #+#    #+#             */
/*   Updated: 2023/11/27 12:55:57 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	long	n_l;

	n_l = n;
	if (n_l < 0)
	{
		write(fd, "-", 1);
		n_l *= -1;
	}
	if (n_l < ft_strlen(base))
		write(fd, &base[n_l], 1);
	else
	{
		ft_putnbr_base_fd(n_l / ft_strlen(base), base, fd);
		ft_putnbr_base_fd(n_l % ft_strlen(base), base, fd);
	}
}
