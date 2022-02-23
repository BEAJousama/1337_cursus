/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:52:52 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/18 22:52:54 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_animation_bonus(t_config *c, void *mlx)
{
	c->enemy[0].img = mlx_xpm_file_to_image(mlx, "assets/enemy/enemy-5.xpm",
			&c->enemy[0].img_width, &c->enemy[0].img_height);
	c->enemy[1].img = mlx_xpm_file_to_image(mlx, "assets/enemy/enemy12.xpm",
			&c->enemy[1].img_width, &c->enemy[1].img_height);
}

void	you_won_bonus(void)
{
	printf("__  __              __       __          \n");
	printf("\\ \\/ /___  __  __   | |     / /___  ____ \n");
	printf(" \\  / __ \\/ / / /   | | /| / / __ \\/ __ \\ \n");
	printf(" / / /_/ / /_/ /    | |/ |/ / /_/ / / / / \n");
	printf("/_/\\____/\\__,_/     |__/|__/\\____/_/ /_/  \n");
	exit(EXIT_SUCCESS);
}

void	you_lost_bonus(void)
{
	printf("  _____                         ____                 \n");
	printf(" / ____|                       / __ \\                \n");
	printf("| |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n");
	printf("| | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__| \n");
	printf("| |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |    \n");
	printf(" \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|    \n");
	printf("\n");
	usleep(300000);
	exit(1);
}
