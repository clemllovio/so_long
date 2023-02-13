/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:42:02 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/08 10:53:17 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collision_wall_up(t_game *game)
{
	if (game->map[(game->p_y - 16) / 64][game->p_x / 64] != '1' && \
	game->map[(game->p_y - 16) / 64][(game->p_x + 63) / 64] != '1')
	{
		if (game->map[(game->p_y - 16) / 64][game->p_x / 64] == 'C')
		{
			game->e.collectible--;
			game->map[(game->p_y - 16) / 64][game->p_x / 64] = '0';
		}
		if (game->map[(game->p_y - 16) / 64][(game->p_x + 63) / 64] == 'C')
		{
			game->e.collectible--;
			game->map[(game->p_y - 16) / 64][(game->p_x + 63) / 64] = '0';
		}
		return (1);
	}
	return (0);
}

int	collision_wall_down(t_game *game)
{
	if (game->map[(game->p_y + 63 + 16) / 64][game->p_x / 64] != '1' && \
	game->map[(game->p_y + 63 + 16) / 64][(game->p_x + 63) / 64] != '1')
	{
		if (game->map[(game->p_y + 63 + 16) / 64][game->p_x / 64] == 'C')
		{
			game->e.collectible--;
			game->map[(game->p_y + 63 + 16) / 64][game->p_x / 64] = '0';
		}
		if (game->map[(game->p_y + 63 + 16) / 64][(game->p_x + 63) / 64] == 'C')
		{
			game->e.collectible--;
			game->map[(game->p_y + 63 + 16) / 64][(game->p_x + 63) / 64] = '0';
		}
		return (1);
	}
	return (0);
}

int	collision_wall_left(t_game *game)
{
	if (game->map[game->p_y / 64][((game->p_x - 16) / 64)] != '1' && \
	game->map[(game->p_y + 63) / 64][((game->p_x - 16) / 64)] != '1')
	{
		if (game->map[game->p_y / 64][((game->p_x - 16) / 64)] == 'C' && \
		game->p_x % 64 >= 20)
		{
			game->e.collectible--;
			game->map[game->p_y / 64][((game->p_x - 16) / 64)] = '0';
		}
		if (game->map[(game->p_y + 63) / 64][((game->p_x - 16) / 64)] == 'C' && \
		game->p_x % 64 >= 20)
		{
			game->e.collectible--;
			game->map[(game->p_y + 63) / 64][((game->p_x - 16) / 64)] = '0';
		}
		return (1);
	}
	return (0);
}

int	collision_wall_right(t_game *game)
{
	if (game->map[game->p_y / 64][(game->p_x + 63 + 16) / 64] != '1' && \
	game->map[(game->p_y + 63) / 64][(game->p_x + 63 + 16) / 64] != '1')
	{
		if (game->map[game->p_y / 64][(game->p_x + 63 + 16) / 64] == 'C' && \
		game->p_x % 64 >= 20)
		{
			game->e.collectible--;
			game->map[game->p_y / 64][(game->p_x + 63 + 16) / 64] = '0';
		}
		if (game->map[(game->p_y + 63) / 64][(game->p_x + 63 + 16) / 64] == 'C' \
		&& game->p_x % 64 >= 20)
		{
			game->e.collectible--;
			game->map[(game->p_y + 63) / 64][(game->p_x + 63 + 16) / 64] = '0';
		}
		return (1);
	}
	return (0);
}
