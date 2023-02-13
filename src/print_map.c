/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:24:01 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/10 10:53:33 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	render_next_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y / 64])
	{
		x = 0;
		print_img(game, x, y);
		y += 64;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.fox, \
	game->p_x, game->p_y);
	game->nb_move = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 22, 27, 1042, game->nb_move);
	free(game->nb_move);
	if (game->e.collectible == 0 && game->map[game->p_y / 64] \
	[game->p_x / 64] == 'E' && game->p_y % 64 <= 20 && game->p_x % 64 <= 20)
	{
		mlx_string_put(game->mlx, game->win, ((game->len * 64) / 2), \
		((game->nbr_line * 64) / 2), 1042, \
		"Congratulation! You finished the game");
		game->e.exit--;
	}
	mlx_do_sync(game->mlx);
	return (0);
}

void	print_img(t_game *game, int x, int y)
{
	while (game->map[y / 64][x / 64])
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x, y);
		if (game->map[y / 64][x / 64] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img.tree, x, y);
		if (game->map[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x, y);
		if (game->map[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->img.coins, \
			x, y);
		x += 64;
	}
}
