/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:35:27 by juramos           #+#    #+#             */
/*   Updated: 2023/12/07 10:00:43 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(char const *format, ...);
size_t	ft_write_s(va_list args);
size_t	ft_write_c(va_list args);
size_t	ft_write_d(va_list args);
size_t	ft_write_x(va_list args);
size_t	ft_write_x_upper(va_list args);
size_t	ft_write_u(va_list args);
size_t	ft_write_ptr(va_list args);
size_t	putnbr_base_with_count_fd(int n, char *base, int fd);
#endif