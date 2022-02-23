/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:13:38 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/11 20:13:44 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mpi_bonus(t_vars v, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(v.mlx, v.win, img_ptr, x, y);
}

static t_coord	get_map_width_height_bonus(char **map)
{
	t_coord	img;

	img.x = 0;
	while (map[img.x])
	{
		img.y = 0;
		while (map[img.x][img.y])
			img.y++;
		img.x++;
	}
	return (img);
}

static t_config	game_config_bonus(void *mlx, char **map)
{
	t_config	config;

	config.wall.img = mlx_xpm_file_to_image(mlx, "assets/rsz_bgtile.xpm",
			&config.wall.img_width, &config.wall.img_height);
	config.player.img = mlx_xpm_file_to_image(mlx, "assets/robot.xpm",
			&config.player.img_width, &config.player.img_height);
	config.door.img = mlx_xpm_file_to_image(mlx, "assets/door2.xpm",
			&config.door.img_width, &config.door.img_height);
	config.coin.img = mlx_xpm_file_to_image(mlx, "assets/coin3.xpm",
			&config.coin.img_width, &config.coin.img_height);
	config.bg.img = mlx_xpm_file_to_image(mlx, "assets/back.xpm",
			&config.bg.img_width, &config.bg.img_height);
	config.size = get_map_width_height_bonus(map);
	enemy_animation_bonus(&config, mlx);
	return (config);
}

void	set_images_bonus(t_map map, t_config c, t_vars v, t_coord p)
{
	static int	x;

	if (x > 1)
		x = 0;
	p.x = -1;
	while (map.map[++p.x])
	{
		p.y = -1;
		while (map.map[p.x][++p.y])
		{
			if (map.map[p.x][p.y] == '1')
				mpi_bonus(v, c.wall.img, p.y * H, p.x * H);
			if (map.map[p.x][p.y] == 'P')
				mpi_bonus(v, c.player.img, p.y * H, p.x * H);
			if (map.map[p.x][p.y] == 'E')
				mpi_bonus(v, c.door.img, p.y * H, p.x * H);
			if (map.map[p.x][p.y] == 'C')
				mpi_bonus(v, c.coin.img, p.y * H, p.x * H);
			if (map.map[p.x][p.y] == '0')
				mpi_bonus(v, c.bg.img, p.y * H, p.x * H);
			if (map.map[p.x][p.y] == 'N')
				mpi_bonus(v, c.enemy[x].img, p.y * H, p.x * H);
		}
	}
	x++;
}

void	map_to_image_bonus(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.config = game_config_bonus(vars.mlx, vars.map.map);
	vars.win = mlx_new_window(vars.mlx, H * vars.config.size.y,
			H * vars.config.size.x, "so_long");
	game_bonus(vars);
	mlx_loop(vars.mlx);
}
