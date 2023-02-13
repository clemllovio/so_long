/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:05:21 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/06 10:48:03 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(n * (-1), count);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', count);
}

void	ft_putnbr_base(long long int nbr, long long int size, \
					char *base, int *count)
{
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = nbr * -1;
		ft_putnbr_base(nbr, size, base, count);
	}
	else if (nbr / size)
	{
		ft_putnbr_base(nbr / size, size, base, count);
		ft_putchar(base[nbr % size], count);
	}
	else
		ft_putchar(base[nbr], count);
}
