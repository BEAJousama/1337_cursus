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

#include "so_long_bonus.h"

t_coord	get_pos_bonus(char **map, char c)
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

static int	move_player_y_bonus(int *count, int y, t_vars *vars)
{
	vars->pos = get_pos_bonus(vars->map.map, 'P');
	if (vars->map.map[vars->pos.x][y] != '1' &&
		vars->map.map[vars->pos.x][y] != 'N')
	{
		*count = print_count_bonus(count, vars, vars->pos.x, y);
		if (vars->map.map[vars->pos.x][y] == 'E' &&
			!check_exit_player_bonus(vars->map.map, 'C'))
		{
			vars->map.map[vars->pos.x][vars->pos.y] = '0';
			vars->map.map[vars->pos.x][y] = 'P';
			you_won_bonus();
		}
		if (vars->map.map[vars->pos.x][y] != 'E')
		{
			vars->map.map[vars->pos.x][vars->pos.y] = '0';
			vars->map.map[vars->pos.x][y] = 'P';
		}
	}
	if (vars->map.map[vars->pos.x][y] == 'N')
	{
		you_lost_bonus();
	}
	return (*count);
}

static int	move_player_x_bonus(int *count, int x, t_vars *vars)
{
	vars->pos = get_pos_bonus(vars->map.map, 'P');
	if (vars->map.map[x][vars->pos.y] != '1' &&
		vars->map.map[x][vars->pos.y] != 'N')
	{
		*count = print_count_bonus(count, vars, x, vars->pos.y);
		if (vars->map.map[x][vars->pos.y] == 'E' &&
			!check_exit_player_bonus(vars->map.map, 'C'))
		{
			vars->map.map[vars->pos.x][vars->pos.y] = '0';
			vars->map.map[x][vars->pos.y] = 'P';
			you_won_bonus();
		}
		if (vars->map.map[x][vars->pos.y] != 'E')
		{
			vars->map.map[vars->pos.x][vars->pos.y] = '0';
			vars->map.map[x][vars->pos.y] = 'P';
		}
	}
	if (vars->map.map[x][vars->pos.y] == 'N')
	{
		you_lost_bonus();
	}
	return (*count);
}

int	ft_input_bonus(int key, void *param)
{
	t_vars		*vars;
	static int	count;

	vars = (t_vars *)param;
	vars->map.item = get_pos_bonus(vars->map.map, 'P');
	mlx_clear_window(vars->mlx, vars->win);
	if (key == D)
		vars->pos.x = move_player_y_bonus(&count, vars->map.item.y + 1, vars);
	else if (key == A)
		vars->pos.x = move_player_y_bonus(&count, vars->map.item.y - 1, vars);
	else if (key == W)
		vars->pos.x = move_player_x_bonus(&count, vars->map.item.x - 1, vars);
	else if (key == S)
		vars->pos.x = move_player_x_bonus(&count, vars->map.item.x + 1, vars);
	else if (key == ESC)
		exit(EXIT_FAILURE);
	else
	{
		printf("Error\nUnauthorized key.\n");
		exit(1);
	}
	set_images_bonus(vars->map, vars->config, *vars, vars->pos);
	mlx_string_put(vars->mlx, vars->win, 20, 15, WHITE, "count : ");
	mlx_string_put(vars->mlx, vars->win, 100, 15, YEL, ft_itoa(vars->pos.x));
	return (0);
}

void	game_bonus(t_vars vars)
{
	t_coord	p;

	p.x = 0;
	p.y = 0;
	set_images_bonus(vars.map, vars.config, vars, p);
	mlx_hook(vars.win, 2, 1L, ft_input_bonus, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_bonus, &vars);
	mlx_loop_hook(vars.mlx, animate_bonus, &vars);
}
