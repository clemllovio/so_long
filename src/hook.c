/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:01:38 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/10 11:48:31 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hook(t_game *game)
{
	game->p_x = game->p_x * 64;
	game->p_y = game->p_y * 64;
	mlx_hook(game->win, ON_KEYDOWN, 27, key_hook, game);
	mlx_hook(game->win, ON_DESTROY, 0, quit, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		return (quit(game), 0);
	if (game->e.exit == 1)
	{
		if ((keycode == W_KEY || keycode == UP_KEY) && \
		collision_wall_up(game) == 1)
			move_up(game);
		if (keycode == A_KEY || keycode == LEFT_KEY)
		{
			game->img.fox = game->img.fox_left;
			if (collision_wall_left(game) == 1)
				move_left(game);
		}
		if ((keycode == S_KEY || keycode == DOWN_KEY) && \
		collision_wall_down(game) == 1)
			move_down(game);
		if (keycode == D_KEY || keycode == RIGHT_KEY)
		{
			game->img.fox = game->img.fox_right;
			if (collision_wall_right(game) == 1)
				move_right(game);
		}
	}
	return (0);
}

int	quit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.coins);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.fox_left);
	mlx_destroy_image(game->mlx, game->img.fox_right);
	mlx_destroy_image(game->mlx, game->img.ground);
	mlx_destroy_image(game->mlx, game->img.tree);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free(game->copy_map, game->nbr_line);
	ft_free(game->map, game->nbr_line);
	exit (0);
	return (0);
}
