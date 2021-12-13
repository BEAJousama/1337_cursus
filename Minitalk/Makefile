# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obeaj <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 17:44:00 by obeaj             #+#    #+#              #
#    Updated: 2021/12/08 17:44:02 by obeaj            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_C =  client.c \
		client_utils.c \

SRCS_S =  server.c \
		server_utils.c \

OBJS_C = $(SRCS_C:%.c=%.o)

OBJS_S = $(SRCS_S:%.c=%.o)

all: client server 

$(CLIENT): $(OBJS_C)
	$(CC) -o $@ $^ $(CFLAGS)

$(SERVER): $(OBJS_S)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	$(RM) $(OBJS_S) $(OBJS_C)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all
