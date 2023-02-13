/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:51:17 by cllovio           #+#    #+#             */
/*   Updated: 2023/02/10 10:56:49 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_elements {
	int			collectible;
	int			exit;
	int			perso;
}	t_elements;

typedef struct s_img {
	void		*tree;
	void		*ground;
	void		*fox;
	void		*coins;
	void		*exit;
	void		*fox_left;
	void		*fox_right;
}	t_img;

typedef struct s_game {
	char				**map;
	char				**copy_map;
	char				*map_file;
	char				*nb_move;
	void				*mlx;
	void				*win;
	size_t				nbr_line;
	size_t				len;
	int					p_y;
	int					p_x;
	int					img_width;
	int					img_height;
	int					gap;
	int					steps;
	t_elements			e;
	t_img				img;
}	t_game;

#endif