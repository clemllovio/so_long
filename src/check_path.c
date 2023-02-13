/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:58:15 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/07 12:03:37 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_copy_map(t_game	*game, int x, int y)
{
	game->copy_map[y][x] = '*';
	if (game->copy_map[y + 1][x] == 'C' || game->copy_map[y + 1][x] == 'E' \
	|| game->copy_map[y + 1][x] == '0')
		change_copy_map(game, x, y + 1);
	if (game->copy_map[y - 1][x] == 'C' || game->copy_map[y - 1][x] == 'E' \
	|| game->copy_map[y - 1][x] == '0')
		change_copy_map(game, x, y - 1);
	if (game->copy_map[y][x - 1] == 'C' || game->copy_map[y][x - 1] == 'E' \
	|| game->copy_map[y][x - 1] == '0')
		change_copy_map(game, x - 1, y);
	if (game->copy_map[y][x + 1] == 'C' || game->copy_map[y][x + 1] == 'E' \
	|| game->copy_map[y][x + 1] == '0')
		change_copy_map(game, x + 1, y);
}

int	check_path(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	change_copy_map(game, game->p_x, game->p_y);
	while (y < game->nbr_line)
	{
		x = 0;
		while (x < game->len)
		{
			if (game->copy_map[y][x] == 'C' || game->copy_map[y][x] == 'E')
				return (ft_printf("Error\nImpossible to finish the game\n"), -1);
			x++;
		}
		y++;
	}
	return (0);
}
