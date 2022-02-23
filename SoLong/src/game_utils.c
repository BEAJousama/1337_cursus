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

#include "so_long.h"

int	ft_close(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	print_count(int *count, t_vars *vars, int x, int y)
{
	if (vars->map.map[x][y] == 'E' &&
		check_exit_player(vars->map.map, 'C'))
		ft_putstr_fd(CANT_EXIT, STDOUT_FILENO);
	else
	{
		*count += 1;
		printf("Count : %d \n", *count);
	}
}
