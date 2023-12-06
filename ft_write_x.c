/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:52:28 by juramos           #+#    #+#             */
/*   Updated: 2023/12/06 10:22:37 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	write_x(va_list args)
{
	unsigned int	value;

	value = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_base_fd(value, "0123456789abcdef", 1);
}

void	write_X(va_list args)
{
	unsigned int	value;

	value = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_base_fd(value, "0123456789ABCDEF", 1);
}
