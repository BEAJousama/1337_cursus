# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obeaj <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 20:02:19 by obeaj             #+#    #+#              #
#    Updated: 2021/12/27 15:11:32 by obeaj            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =  game.c \
		map_parser_utils.c \
		map_parser.c \
		map_to_image.c \
		so_long.c \
		game_utils.c \
		gnl.c \

SRCS_B = game_bonus.c \
		map_parser_utils_bonus.c \
		map_parser_bonus.c \
		map_to_image_bonus.c \
		so_long_bonus.c \
		game_utils_bonus.c \
		gnl_bonus.c \
		so_long_utils_bonus.c \

OBJS  = ${addprefix src/,${SRCS:.c=.o}}

OBJS_B  = ${addprefix src/bonus/,${SRCS_B:.c=.o}}

LD_FLAGS = -L libft

MLX_FLAGS  =  -lmlx -framework OpenGL -framework AppKit

HEAD  = -I includes -I libft

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o :
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	make -C libft
	${CC} ${CFLAGS} ${LD_FLAGS} -lft ${MLX_FLAGS} ${OBJS} -o $@

all : ${NAME}

bonus : ${OBJS_B}
	make -C libft
	${CC} ${CFLAGS} ${LD_FLAGS} -lft ${MLX_FLAGS} ${OBJS_B} -o ${NAME} 

clean :
	make clean -C libft
	@rm -rf ${OBJS} ${OBJS_B}

fclean : clean
	make fclean -C libft
	@rm -rf ${NAME}

re : fclean all
