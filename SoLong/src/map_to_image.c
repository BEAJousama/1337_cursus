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

#include "so_long.h"

static t_coord	get_map_width_height(char **map)
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

static t_config	game_config(void *mlx, char **map)
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
	config.size = get_map_width_height(map);
	return (config);
}

void	set_images(t_map map, t_config config, t_vars vars)
{
	map.item.x = 0;
	while (map.map[map.item.x])
	{
		map.item.y = 0;
		while (map.map[map.item.x][map.item.y])
		{
			if (map.map[map.item.x][map.item.y] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, config.wall.img,
					0 + map.item.y * H, 0 + map.item.x * H);
			if (map.map[map.item.x][map.item.y] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, config.player.img,
					0 + map.item.y * H, 0 + map.item.x * H);
			if (map.map[map.item.x][map.item.y] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, config.door.img,
					0 + map.item.y * H, 0 + map.item.x * H);
			if (map.map[map.item.x][map.item.y] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, config.coin.img,
					0 + map.item.y * H, 0 + map.item.x * H);
			map.item.y++;
		}
		map.item.x++;
	}	
}

void	map_to_image(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.config = game_config(vars.mlx, vars.map.map);
	vars.win = mlx_new_window(vars.mlx, H * vars.config.size.y,
			H * vars.config.size.x, "so_long");
	set_images(vars.map, vars.config, vars);
	game(vars);
	mlx_loop(vars.mlx);
}
