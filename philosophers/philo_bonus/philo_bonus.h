/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:26:07 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/19 13:26:09 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define USAGE "Usage : ./philo <nph> <t2d> <t2e> <t2s> [optional : Nt2e]"
# define INVALID_ARGS "Error : Make sure the args are numbers and are positive."
# define N_PHLOS "Please make sure there is less than 200 philosopher."
# define OVERFLOW "Please make sure the integers are <= MAX_INT and >= MIN_INT"
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/wait.h>

typedef struct s_philo
{
	pthread_t		master;
	sem_t			*eating;
	long long		lta;
	long long		lts;
	int				slave;
	int				nta;
	int				pid;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	t_philo			**philos;
	sem_t			*forks;
	sem_t			*write;
	long long		tval;
	int				nph;
	int				tte;
	int				tts;
	int				ttd;
	int				nte;
}	t_table;

void		*routine(void *data);
void		*watchers(void *data);
long		ft_atoi(const char *str);
long long	time_in_ms(void);
void		print_error(char *s);
void		ft_putendl_fd(char *s, int fd);
void		print_status(t_table *table, int pid, char *s);
void		kill_philos(t_table *table);
int			check_args(int ac, char **av);
void		freetable(t_table *table);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);

#endif