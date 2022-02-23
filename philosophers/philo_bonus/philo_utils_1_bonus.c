/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:59:19 by obeaj             #+#    #+#             */
/*   Updated: 2022/02/16 11:59:21 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	time_in_ms(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, 0);
	ms = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	return (ms);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i *= -1;
	}
	if (i < 10)
	{
		ft_putchar_fd(i + 48, fd);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}

void	print_status(t_table *table, int pid, char *s)
{
	sem_wait(table->write);
	ft_putnbr_fd(time_in_ms() - table->tval, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(s, 1);
	if (*s != 'd')
		sem_post(table->write);
	else
		exit(1);
}

void	kill_philos(t_table *table)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (i < table->nph)
	{
		j = 0;
		waitpid(-1, &status, 0);
		while (j < table->nph)
			kill(table->philos[j++]->slave, SIGKILL);
		if (sem_close(table->philos[i]->eating))
			return ;
		if (pthread_detach(table->philos[i]->master))
			return ;
		free(table->philos[i]);
		i++;
	}
	if (sem_close(table->write))
		return ;
	if (sem_close(table->forks))
		return ;
	free(table->philos);
	free(table);
}
