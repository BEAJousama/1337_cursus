/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:45:24 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/14 23:45:28 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_bonus(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	set_enemy_bonus(char **map)
{
	t_coord	pos;

	pos = get_pos_bonus(map, '0');
	map[pos.x][pos.y] = 'N';
}

static void	animate_util_bonus(t_coord pos, t_vars vars, char c)
{
	int	rand;

	rand = arc4random_uniform(100) % 50;
	if (vars.map.map[pos.x][pos.y + 1] == c && (rand % 2))
	{
		vars.map.map[pos.x][pos.y] = c;
		vars.map.map[pos.x][pos.y + 1] = 'N';
	}
	else if (vars.map.map[pos.x - 1][pos.y] == c && (rand % 2))
	{
		vars.map.map[pos.x][pos.y] = c;
		vars.map.map[pos.x - 1][pos.y] = 'N';
	}
	else if (vars.map.map[pos.x][pos.y - 1] == c && !(rand % 2))
	{
		vars.map.map[pos.x][pos.y] = c;
		vars.map.map[pos.x][pos.y - 1] = 'N';
	}
	else if (vars.map.map[pos.x + 1][pos.y] == c && !(rand % 2))
	{
		vars.map.map[pos.x][pos.y] = c;
		vars.map.map[pos.x + 1][pos.y] = 'N';
	}
}

int	animate_bonus(void *param)
{
	t_coord			pos;
	static t_coord	p;
	static t_vars	*vars;

	vars = (t_vars *)param;
	pos = get_pos_bonus(vars->map.map, 'N');
	if (p.x++ < 50)
	{
		animate_util_bonus(pos, *vars, '0');
		if (p.x >= 50)
			p.y = 0;
	}
	else
	{
		if (p.y++ < 50)
		{
			animate_util_bonus(pos, *vars, '0');
			if (p.y >= 50)
				p.x = 0;
		}
	}
	set_images_bonus(vars->map, vars->config, *vars, p);
	usleep(260000);
	return (0);
}

int	print_count_bonus(int *count, t_vars *vars, int x, int y)
{
	if (vars->map.map[x][y] == 'E' &&
		check_exit_player_bonus(vars->map.map, 'C'))
		ft_putstr_fd(CANT_EXIT, 1);
	else
		*count += 1;
	return (*count);
}
