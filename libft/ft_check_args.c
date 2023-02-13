/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:26:15 by cllovio           #+#    #+#             */
/*   Updated: 2023/01/04 16:13:35 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_args(char format, va_list args, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_base(va_arg(args, long long unsigned int), \
			16, "0123456789abcdef", count);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), 10, "0123456789", count);
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), \
			16, "0123456789abcdef", count);
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), 16,
			"0123456789ABCDEF", count);
	else if (format == '%')
		ft_putchar('%', count);
}
