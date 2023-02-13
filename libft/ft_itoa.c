/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:04:27 by cllovio           #+#    #+#             */
/*   Updated: 2022/11/22 15:19:52 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int		count;
	long	div;

	count = 0;
	div = 1;
	if (n <= 0)
	{
		n = n * -1;
		count++;
	}
	while (n / div > 0)
	{
		div = div * 10;
		count++;
	}
	return (count);
}

static char	*ft_rev_tab(char *s)
{
	int	temp;
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < (len / 2))
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
		i++;
	}
	return (s);
}

static char	*ft_convert(char *s, int n)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		n = n * -1;
		sign = -1;
	}
	while (n > 0)
	{
		s[i++] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc(sizeof(char) * (ft_count(n) + 1));
	if (!s)
		return (NULL);
	ft_convert(s, n);
	ft_rev_tab(s);
	return (s);
}
