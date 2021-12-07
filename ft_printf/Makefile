# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obeaj <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 15:37:18 by obeaj             #+#    #+#              #
#    Updated: 2021/11/28 15:37:23 by obeaj            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc
CC_FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f


SRCS =  ft_printf.c \
		ft_charConvert.c \
		ft_vprintf.c \
		ft_conversion.c \
		ft_intConvert.c \
		ft_strConvert.c \
		ft_printf_utils.c \
		ft_percentConvert.c \
		ft_uintConvert.c \
		ft_hexConvert.c \
		ft_pointerConvert.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) 	

fclean: clean
	$(RM) $(NAME)

re: fclean all
