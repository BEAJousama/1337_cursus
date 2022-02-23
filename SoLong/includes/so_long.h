/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:07:32 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/11 12:07:35 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include "constants.h"
# include "structs.h"
# include <stdio.h>
# include <fcntl.h>

void	map_parser(char **av);
char	*get_next_line(int fd);
void	print_error(char *error, char **map);
void	freetab(char **tab);
int		get_map_len(int fd);
int		check_wall(char *wall);
int		check_elements(char *line);
void	map_to_image(t_vars vars);
void	set_images(t_map map, t_config config, t_vars vars);
void	game(t_vars vars);
int		check_exit_player(char **map, char c);
int		ft_close(void);
void	print_count(int *count, t_vars *vars, int x, int y);
void	map_parser_bonus(char **av);
char	*get_next_line_bonus(int fd);
void	print_error_bonus(char *error, char **map);
void	freetab_bonus(char **tab);
int		get_map_len_bonus(int fd);
int		check_wall_bonus(char *wall);
int		check_elements_bonus(char *line);
void	map_to_image_bonus(t_vars vars);
void	set_images_bonus(t_map map, t_config c, t_vars v, t_coord p);
void	game_bonus(t_vars vars);
int		check_exit_player_bonus(char **map, char c);
int		ft_close_bonus(void);
int		print_count_bonus(int *count, t_vars *vars, int x, int y);
int		animate_bonus(void *param);
void	set_enemy_bonus(char **map);
t_coord	get_pos_bonus(char **map, char c);
int		ft_input_bonus(int key, void *param);
void	mpi_bonus(t_vars v, void *img_ptr, int x, int y);
void	enemy_animation_bonus(t_config *c, void *mlx);
void	you_lost_bonus(void);
void	you_won_bonus(void);
#endif
