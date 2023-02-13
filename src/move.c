/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:35:21 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/08 13:10:46 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	game->p_y -= game->gap;
	game->steps++;
	ft_printf("%d,", game->steps);
}

void	move_down(t_game *game)
{
	game->p_y += game->gap;
	game->steps++;
	ft_printf("%d,", game->steps);
}

void	move_left(t_game *game)
{
	game->p_x -= game->gap;
	game->steps++;
	ft_printf("%d,", game->steps);
}

void	move_right(t_game *game)
{
	game->p_x += game->gap;
	game->steps++;
	ft_printf("%d,", game->steps);
}
