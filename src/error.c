/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:36:34 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/08 13:16:43 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(t_game *game)
{
	size_t	len;

	len = ft_strlen(game->map_file);
	if (game->map_file[len - 1] == 'r' && game->map_file[len - 2] == 'e' \
	&& game->map_file[len - 3] == 'b' && game->map_file [len - 4] == '.')
		return (0);
	return (ft_printf("Error\nInvalid map name\n"), -1);
}

int	check_rectangle(t_game *game)
{
	size_t	i;

	game->len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (game->len != ft_strlen(game->map[i]))
			return (ft_printf("Error\nThe map is not a rectangle\n"), -1);
		i++;
	}
	return (0);
}

int	check_wall(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->len)
	{
		if (game->map[0][i] != '1' || game->map[game->nbr_line -1][i] != '1')
			return (ft_printf("Error\nThe map is not surrounded by walls\n"), -1);
		i++;
	}
	i = 0;
	while (i < game->nbr_line)
	{
		if (game->map[i][0] != '1' || game->map[i][game->len - 1] != '1')
			return (ft_printf("Error\nThe map is not surrounded by walls\n"), -1);
		i++;
	}
	return (0);
}

int	check_map_element(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->nbr_line)
	{
		x = 0;
		while (x < game->len)
		{
			if (map_is_valid(game, x, y) == -1)
				return (ft_printf("Error\nWrong characters in the map\n"), -1);
			if (game->map[y][x] == 'C')
				game->e.collectible++;
			if (game->map[y][x] == 'P')
				game->e.perso++;
			if (game->map[y][x] == 'E')
				game->e.exit++;
			x++;
		}
		y++;
	}
	if (game->e.collectible < 1 || game->e.exit != 1 || game->e.perso != 1)
		return (ft_printf("Error\nWrong number of elements\n"), -1);
	return (0);
}

int	map_is_valid(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == '1' || \
	game->map[y][x] == 'C' || game->map[y][x] == 'E' || game->map[y][x] == 'P')
	{
		if (game->map[y][x] == 'P')
		{
			game->p_y = y;
			game->p_x = x;
		}
		return (0);
	}
	return (-1);
}
