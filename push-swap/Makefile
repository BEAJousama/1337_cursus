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

PUSHSWAP = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_C =  checker.c \
		  fillstack.c \
		  ft_atoi.c \
		  ft_split.c \
		  ft_strjoin.c \
		  pushing.c \
		  rotate.c \
		  rvrotate.c \
		  stackutils.c \
		  swaping.c \
		  gnl.c \
		  checkutils.c \
		  pushswap_utils.c

SRCS_P =  pushswap.c \
		  sorting.c \
		  fillstack.c \
		  ft_atoi.c \
		  ft_split.c \
		  ft_strjoin.c \
		  pushing.c \
		  rotate.c \
		  rvrotate.c \
		  stackutils.c \
		  swaping.c \
		  gnl.c \
		  checkutils.c \
		  pushswap_utils.c \
		  sorting_utils.c

OBJS_C = $(SRCS_C:%.c=%.o)

OBJS_P = $(SRCS_P:%.c=%.o)

all: push_swap checker 

$(PUSHSWAP): $(OBJS_P)
	$(CC) -o $@ $^ $(CFLAGS)

$(CHECKER): $(OBJS_C)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	$(RM) $(OBJS_P) $(OBJS_C)

fclean: clean
	$(RM) $(PUSHSWAP) $(CHECKER)

re: fclean all
