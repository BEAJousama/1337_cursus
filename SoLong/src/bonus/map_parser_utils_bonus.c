/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:46:40 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/11 11:46:42 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error_bonus(char *error, char **map)
{
	if (!map || *map)
	{
		printf("Error\nInvalid map : %s", error);
		exit(EXIT_FAILURE);
	}
	else
	{
		freetab_bonus(map);
		printf("Error\nInvalid map : %s", error);
		exit(EXIT_FAILURE);
	}
}

void	freetab_bonus(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	get_map_len_bonus(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line_bonus(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line_bonus(fd);
	}
	close(fd);
	return (i);
}

int	check_elements_bonus(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(_ELEMENTS, line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_bonus(char *wall)
{
	int	i;

	i = 0;
	while (wall[i] && wall[i] != '\n')
	{
		if (wall[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
