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

#ifndef PHILO_H
# define PHILO_H
# define USAGE "Usage : ./philo <nph> <t2d> <t2e> <t2s> [optional : Nt2e]"
# define INVALID_ARGS "Error : Make sure the args are numbers and are positive."
# define N_PHLOS "Please make sure there is less than 200 philosopher."
# define OVERFLOW "Please make sure the inte gers are <= MAX_INT and >= MIN_INT"
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		slave;
	pthread_t		master;
	pthread_mutex_t	eating;
	int				lfork;
	int				rfork;
	long long		lta;
	long long		lts;
	int				pid;
	int				iseating;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	*forks;
	t_philo			**philos;
	pthread_mutex_t	write;
	long long		tval;
	int				nph;
	int				tte;
	int				tts;
	int				ttd;
	int				nta;
	int				nte;
	int				death;
	int				index;
}	t_table;

void		*routine(void *data);
void		*watchers(void *data);
long		ft_atoi(const char *str);
long long	time_in_ms(void);
int			print_error(char *s);
void		freetable(t_table *table);
void		print_status(t_table *table, int pid, char *s);
int			check_args(int ac, char **av);
int			threads_exit(t_table *table);

#endif