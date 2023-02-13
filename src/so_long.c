/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:45:15 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/10 12:38:31 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_error(t_game *game)
{
	if (game->nbr_line == 0)
		return (ft_printf("Error\nInvalid map\n"), -1);
	if (check_map_name(game) == -1)
		return (-1);
	if (check_rectangle(game) == -1)
		return (-1);
	if (check_wall(game) == -1)
		return (-1);
	if (check_map_element(game) == -1)
		return (-1);
	if (check_path(game) == -1)
		return (-1);
	return (0);
}

int	mlx(t_game	*game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		return (ft_printf("Error\n"), -1);
	}
	game->win = mlx_new_window(game->mlx, game->len * 64, game->nbr_line * 64, \
	"so_long");
	if (game->win == NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ft_printf("Error\n"), -1);
	}
	if (load_image_1(game) == -1)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ft_printf("Error\n"), -1);
	}
	game->img.fox = game->img.fox_right;
	hook(game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_printf("Error\nWrong number of arguments\n"), -1);
	init(&game);
	game.map_file = av[1];
	if (read_map(&game) == -1)
	{
		ft_free(game.map, game.nbr_line);
		ft_free(game.copy_map, game.nbr_line);
		return (-1);
	}
	if (check_error(&game) == -1)
	{
		ft_free(game.map, game.nbr_line);
		ft_free(game.copy_map, game.nbr_line);
		return (-1);
	}
	if (mlx(&game) == -1)
	{
		ft_free(game.copy_map, game.nbr_line);
		ft_free(game.map, game.nbr_line);
		return (-1);
	}
	return (0);
}
