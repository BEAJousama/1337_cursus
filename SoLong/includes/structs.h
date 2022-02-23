/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:12:35 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/11 12:12:37 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_coord
{
	size_t	x;
	size_t	y;
}	t_coord;
typedef struct s_map
{
	char	**map;
	char	*line;
	t_coord	item;
	int		map_len;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		img_height;
	int		img_width;
	int		endian;
}	t_data;

typedef struct s_config
{
	t_data		wall;
	t_data		player;
	t_data		door;
	t_data		coin;
	t_data		enemy[11];
	t_data		bg;
	t_coord		size;
}	t_config;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_config	config;
	t_coord		pos;
}	t_vars;

#endif