/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:07:23 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/11 12:11:35 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define H 50
# define ESC 53
# define W 13
# define S 1
# define D 2
# define A 0
# define WHITE 0xffffff
# define YEL 0xffff00
# define DESTROY_NOTIFY 17
# define _ELEMENTS "01CEP\n"
# define EMPTY_MAP "Your map is empty.\n"
# define EXTRA_ELEMENT "The map should contain only 01ECP characters.\n"
# define NOT_RECTANGULAR "Please make sure the map is rectangular.\n"
# define NO_WALLS "Please make sure the map is surrounded by walls.\n"
# define USAGE "Usage : ./so_long <file.ber>\n"
# define NO_EXIT "Please make sure the map contains at least one exit.\n"
# define NO_COINS "Please make sure the map contains at least one collectible.\n"
# define NO_PLAYER "Please make sure the map contains a player position.\n"
# define MULTIPLE_PLAYERS "The map should contain only one player position.\n"
# define CANT_EXIT "You cannot exit unless you eat all collectibles\n"
# define NOT_BER "Make sure the map is a .ber file !\n"
#endif
