/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:52:05 by juramos           #+#    #+#             */
/*   Updated: 2023/11/28 12:33:09 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_write_s(va_list args)
{
	char	*value;
	size_t	pos;

	pos = 0;
	value = va_arg(args, char *);
	while (value[pos])
	{
		write(1, &value[pos], 1);
		pos++;
	}
	return (pos);
}
