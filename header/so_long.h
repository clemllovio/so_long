/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:45:23 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/10 12:34:31 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

// Librairies
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "structure.h"
# include <stdlib.h>
# include <fcntl.h>

# define LEFT_KEY				65361
# define RIGHT_KEY				65363
# define UP_KEY					65362
# define DOWN_KEY				65364
# define A_KEY					97
# define W_KEY					119
# define S_KEY					115
# define D_KEY					100
# define ESC					65307

// so_long.c
int		check_error(t_game *game);
int		mlx(t_game	*game);

// utils.c
void	init(t_game *game);
void	ft_free(char **tab, int j);
int		load_image_1(t_game *game);
int		load_image_2(t_game *game);
int		load_image_3(t_game *game);

// create_map.c
int		read_map(t_game *game);
int		fill_map(t_game	*game);
void	del_return_line(char **map, t_game *game);
int		copy_map(t_game *game);

// error.c
int		check_map_name(t_game *game);
int		check_rectangle(t_game *game);
int		check_wall(t_game *game);
int		check_map_element(t_game *game);
int		map_is_valid(t_game *game, int x, int y);

// check_path.c
void	change_copy_map(t_game	*game, int x, int y);
int		check_path(t_game *game);

// hook.c
void	hook(t_game	*game);
int		key_hook(int keycode, t_game *game);
int		quit(t_game *game);

// print_map.c
int		render_next_frame(t_game *game);
void	print_img(t_game *game, int x, int y);

// move.c
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// collision.c
int		collision_wall_up(t_game *game);
int		collision_wall_down(t_game *game);
int		collision_wall_left(t_game *game);
int		collision_wall_right(t_game *game);

#endif