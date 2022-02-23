/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:37:52 by obeaj             #+#    #+#             */
/*   Updated: 2022/02/08 10:37:53 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_in_ms(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, 0);
	ms = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	return (ms);
}

void	print_status(t_table *table, int pid, char *s)
{
	if (pthread_mutex_lock(&table->write))
		return ;
	printf("%lld %d %s", time_in_ms() - table->tval, pid, s);
	if (*s != 'd')
	{
		if (pthread_mutex_unlock(&table->write))
			return ;
	}
}

int	threads_exit(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nph)
	{
		if (pthread_detach(table->philos[i]->master))
			return (-1);
		if (pthread_detach(table->philos[i]->slave))
			return (-2);
		if (pthread_mutex_destroy(&table->forks[i]))
			return (-3);
		if (pthread_mutex_destroy(&table->philos[i]->eating))
			return (-4);
		free(table->philos[i]);
		i++;
	}
	if (pthread_mutex_destroy(&table->write))
		return (-5);
	free(table->philos[i]);
	free(table->philos);
	free(table->forks);
	free(table);
	return (0);
}

void	freetable(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nph)
	{
		free(table->philos[i]);
		i++;
	}
	free(table->philos[i]);
	free(table->philos);
	free(table->forks);
	free(table);
}
