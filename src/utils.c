/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:47:00 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/10 12:33:25 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game)
{
	game->map = NULL;
	game->copy_map = NULL;
	game->map_file = NULL;
	game->nb_move = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->img.coins = NULL;
	game->img.exit = NULL;
	game->img.fox = NULL;
	game->img.fox_left = NULL;
	game->img.fox_right = NULL;
	game->img.ground = NULL;
	game->img.tree = NULL;
	game->nbr_line = 0;
	game->len = 0;
	game->p_y = 0;
	game->p_x = 0;
	game->gap = 16;
	game->steps = 0;
	game->e.collectible = 0;
	game->e.exit = 0;
	game->e.perso = 0;
}

void	ft_free(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	load_image_1(t_game *game)
{
	game->img.ground = mlx_xpm_file_to_image(game->mlx, "image/fond.xpm", \
	&game->img_width, &game->img_height);
	if (game->img.ground == NULL)
		return (-1);
	game->img.tree = mlx_xpm_file_to_image(game->mlx, "image/Tree.xpm", \
	&game->img_width, &game->img_height);
	if (game->img.tree == NULL)
	{
		mlx_destroy_image(game->mlx, game->img.ground);
		return (-1);
	}
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "image/exit.xpm", \
	&game->img_width, &game->img_height);
	if (game->img.exit == NULL)
	{
		mlx_destroy_image(game->mlx, game->img.ground);
		mlx_destroy_image(game->mlx, game->img.tree);
		return (-1);
	}
	if (load_image_2(game) == -1)
		return (-1);
	return (0);
}

int	load_image_2(t_game *game)
{
	game->img.coins = mlx_xpm_file_to_image(game->mlx, "image/coin.xpm", \
	&game->img_width, &game->img_height);
	if (game->img.coins == NULL)
	{
		mlx_destroy_image(game->mlx, game->img.exit);
		mlx_destroy_image(game->mlx, game->img.ground);
		mlx_destroy_image(game->mlx, game->img.tree);
		return (-1);
	}
	game->img.fox_left = mlx_xpm_file_to_image(game->mlx, \
	"image/perso_left.xpm", &game->img_width, &game->img_height);
	if (game->img.fox_left == NULL)
	{
		mlx_destroy_image(game->mlx, game->img.coins);
		mlx_destroy_image(game->mlx, game->img.exit);
		mlx_destroy_image(game->mlx, game->img.ground);
		mlx_destroy_image(game->mlx, game->img.tree);
		return (-1);
	}
	if (load_image_3(game) == -1)
		return (-1);
	return (0);
}

int	load_image_3(t_game *game)
{
	game->img.fox_right = mlx_xpm_file_to_image(game->mlx, "image/perso.xpm", \
	&game->img_width, &game->img_height);
	if (game->img.fox_right == NULL)
	{
		mlx_destroy_image(game->mlx, game->img.fox_left);
		mlx_destroy_image(game->mlx, game->img.coins);
		mlx_destroy_image(game->mlx, game->img.exit);
		mlx_destroy_image(game->mlx, game->img.ground);
		mlx_destroy_image(game->mlx, game->img.tree);
		return (-1);
	}
	return (0);
}
