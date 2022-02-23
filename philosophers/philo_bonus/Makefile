NAME = philo_bonus

SRCS =  philo_bonus.c \
		philo_utils_bonus.c \
		philo_routine_bonus.c \
		philo_utils_1_bonus.c \
		philo_utils_2_bonus.c \

OBJS  = ${addprefix ./,${SRCS:.c=.o}}

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = philo_bonus.h

%.o:%.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

all : ${NAME}

clean :
	@rm -rf ${OBJS}

fclean : clean
	@rm -rf ${NAME}

re : fclean all