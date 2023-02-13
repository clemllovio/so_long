/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:23:11 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/10 12:29:18 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_game *game)
{
	int		fd;
	char	*temp;

	fd = open(game->map_file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nThe file could not be opened\n"), -1);
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		game->nbr_line++;
		free(temp);
	}
	close(fd);
	if (fill_map(game) == -1)
		return (-1);
	return (0);
}

int	fill_map(t_game	*game)
{
	int		fd;
	size_t	i;

	game->map = malloc(sizeof(char *) * (game->nbr_line + 1));
	if (!(game->map))
		return (ft_printf("Error\nA malloc failed\n"), -1);
	fd = open(game->map_file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nThe file could not be opened\n"), -1);
	i = 0;
	while (i < game->nbr_line)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			return (close(fd), ft_printf("Error\nA malloc failed\n"), -1);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	del_return_line(game->map, game);
	if (copy_map(game) == -1)
		return (-1);
	return (0);
}

void	del_return_line(char **map, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->nbr_line)
	{
		game->len = ft_strlen(map[i]);
		if (map[i][game->len - 1] == '\n')
			map[i][game->len - 1] = '\0';
		i++;
	}
}

int	copy_map(t_game *game)
{
	size_t	i;
	int		fd;

	i = 0;
	game->copy_map = malloc(sizeof(char *) * (game->nbr_line + 1));
	if (!(game->copy_map))
		return (ft_printf("Error\nA malloc failed\n"), -1);
	fd = open(game->map_file, O_RDONLY);
	while (i < game->nbr_line)
	{
		game->copy_map[i] = get_next_line(fd);
		if (game->copy_map[i] == NULL)
			return (close (fd), ft_printf("Error\nA malloc failed\n"), -1);
		i++;
	}
	game->copy_map[i] = NULL;
	close(fd);
	del_return_line(game->copy_map, game);
	return (0);
}
