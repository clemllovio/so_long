/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:49:35 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/10 12:49:39 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	next_line_len(char *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
		{
			return (i);
		}
		i++;
	}
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*str_src;
	char		*str_dst;

	if (!dst && !src)
		return (dst);
	str_dst = dst;
	str_src = src;
	if (str_dst < str_src)
	{
		while (len-- > 0)
			*str_dst++ = *str_src++;
		*str_dst = '\0';
	}
	else
	{
		str_src = src + (len - 1);
		str_dst = dst + (len);
		*str_dst-- = '\0';
		while (len-- > 0)
			*str_dst-- = *str_src--;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		pos;
	char	*tab;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(tab))
		return (NULL);
	i = 0;
	pos = 0;
	while (s1[i] != '\0')
		tab[pos++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		tab[pos++] = s2[i++];
	tab[pos] = '\0';
	free(s1);
	free(s2);
	return (tab);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *buffer)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(buffer);
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	while (buffer[i])
	{
		dest[i] = buffer[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
