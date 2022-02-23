/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:13:14 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/13 17:13:16 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_coord	get_pos(char **map, char c)
{
	t_coord	pos;

	pos.x = 0;
	while (map[pos.x])
	{
		pos.y = 0;
		while (map[pos.x][pos.y])
		{
			if (map[pos.x][pos.y] == c)
				return (pos);
			pos.y++;
		}
		pos.x++;
	}
	return (pos);
}

static void	move_player_y(int *count, int y, t_vars *vars)
{
	t_coord	pos;

	pos = get_pos(vars->map.map, 'P');
	if (vars->map.map[pos.x][y] != '1')
	{
		print_count(count, vars, pos.x, y);
		if (vars->map.map[pos.x][y] == 'E' &&
			!check_exit_player(vars->map.map, 'C'))
		{
			vars->map.map[pos.x][pos.y] = '0';
			vars->map.map[pos.x][y] = 'P';
			printf("You win.\n");
			exit(EXIT_SUCCESS);
		}
		if (vars->map.map[pos.x][y] != 'E')
		{
			vars->map.map[pos.x][pos.y] = '0';
			vars->map.map[pos.x][y] = 'P';
		}
		set_images(vars->map, vars->config, *vars);
	}
}

static void	move_player_x(int *count, int x, t_vars *vars)
{
	t_coord	pos;

	pos = get_pos(vars->map.map, 'P');
	if (vars->map.map[x][pos.y] != '1')
	{
		print_count(count, vars, x, pos.y);
		if (vars->map.map[x][pos.y] == 'E' &&
			!check_exit_player(vars->map.map, 'C'))
		{
			vars->map.map[pos.x][pos.y] = '0';
			vars->map.map[x][pos.y] = 'P';
			printf("You win.\n");
			exit(EXIT_SUCCESS);
		}
		if (vars->map.map[x][pos.y] != 'E')
		{
			vars->map.map[pos.x][pos.y] = '0';
			vars->map.map[x][pos.y] = 'P';
		}
		set_images(vars->map, vars->config, *vars);
	}
}

static int	ft_input(int key, void *param)
{
	t_vars		*vars;
	t_coord		pos;
	static int	count;

	vars = (t_vars *)param;
	pos = get_pos(vars->map.map, 'P');
	mlx_clear_window(vars->mlx, vars->win);
	if (key == D)
		move_player_y(&count, pos.y + 1, vars);
	else if (key == A)
		move_player_y(&count, pos.y - 1, vars);
	else if (key == W)
		move_player_x(&count, pos.x - 1, vars);
	else if (key == S)
		move_player_x(&count, pos.x + 1, vars);
	else if (key == ESC)
		exit(EXIT_FAILURE);
	else
	{
		printf("Error\nUnothorized key.\n");
		exit(1);
	}
	set_images(vars->map, vars->config, *vars);
	return (0);
}

void	game(t_vars vars)
{
	mlx_hook(vars.win, 2, 1L, ft_input, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
}
