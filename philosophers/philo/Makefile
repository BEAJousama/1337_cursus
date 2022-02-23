NAME = philo

SRCS =  philo.c \
		philo_utils.c \
		philo_routine.c \
		philo_utils_1.c \

OBJS  = ${addprefix ./,${SRCS:.c=.o}}

CC = cc
CFLAGS = -Wall -Werror -Wextra 
INCLUDE = philo.h

%.o:%.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : ${OBJS} philo.h
	${CC} ${CFLAGS} ${OBJS} -o $@

all : ${NAME}

clean :
	@rm -rf ${OBJS}

fclean : clean
	@rm -rf ${NAME}

re : fclean all