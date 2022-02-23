/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:46:23 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/11 11:46:26 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_path(char **av)
{
	char	**t;
	int		i;
	int		fd;

	t = ft_split(av[1], '.');
	i = 0;
	while (t[i])
		i++;
	if (ft_strncmp(t[i - 1], "ber", 5))
	{
		printf("Error\n%s", NOT_BER);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	freetab(t);
}

static char	**check_map(int fd, char **av)
{
	t_map	map;
	int		file;

	file = open(av[1], O_RDONLY);
	map.map_len = get_map_len(fd);
	map.line = get_next_line(file);
	map.map = (char **)malloc((map.map_len + 1) * sizeof(char **));
	map.item.x = ft_strlen(map.line);
	map.item.y = 0;
	if (!map.line || !*map.line)
		print_error(EMPTY_MAP, map.map);
	while (map.map_len--)
	{
		if (!check_elements(map.line))
			print_error(EXTRA_ELEMENT, map.map);
		if (ft_strlen(map.line) != map.item.x)
			print_error(NOT_RECTANGULAR, map.map);
		if (map.line[0] != '1' || map.line[ft_strlen(map.line) - 1] != '1')
			print_error(NO_WALLS, map.map);
		map.map[map.item.y++] = ft_strdup(map.line);
		free(map.line);
		map.line = get_next_line(file);
	}
	map.map[map.item.y] = 0;
	return (map.map);
}

int	check_exit_player(char **map, char c)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				found++;
			j++;
		}
		i++;
	}
	return (found);
}

static void	check_map_2(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (ft_strchr(map[i - 1], '\n'))
		print_error(NOT_RECTANGULAR, map);
	if (check_wall(map[0]) || check_wall(map[i - 1]))
		print_error(NO_WALLS, map);
	if (!check_exit_player(map, 'E'))
		print_error(NO_EXIT, map);
	if (!check_exit_player(map, 'P'))
		print_error(NO_PLAYER, map);
	if (!check_exit_player(map, 'C'))
		print_error(NO_COINS, map);
	if (check_exit_player(map, 'P') > 1)
		print_error(MULTIPLE_PLAYERS, map);
}

void	map_parser(char **av)
{
	int		fd;
	t_vars	vars;

	check_path(av);
	fd = open(av[1], O_RDONLY);
	vars.map.map = check_map(fd, av);
	check_map_2(vars.map.map);
	map_to_image(vars);
	freetab(vars.map.map);
}
