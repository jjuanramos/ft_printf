/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:13:26 by juramos           #+#    #+#             */
/*   Updated: 2023/11/27 11:48:13 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	char	c;
	long	helper;

	helper = (unsigned long)n;
	if (helper < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_base_fd(helper * -1, base, fd);
	}
	else if (helper < ft_strlen(base))
	{
		c = base[helper];
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_base_fd(helper / ft_strlen(base), base, fd);
		ft_putnbr_base_fd(helper % ft_strlen(base), base, fd);
	}
}

int main(void)
{
	// ft_putnbr_base_fd(-2147483648, "0123456789", 1);
	// printf("\n");
	ft_putnbr_base_fd(0xA, "0123456789abcdef", 1);
	printf("\n");
	return (0);
}
