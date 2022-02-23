/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:37:31 by obeaj             #+#    #+#             */
/*   Updated: 2022/02/08 10:37:35 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think_philo(t_philo *philo)
{
	print_status(philo->table, philo->pid, "is thinking\n");
}

static void	eat_philo(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->table->forks[philo->lfork]))
		return ;
	print_status(philo->table, philo->pid, "has taken a fork\n");
	if (pthread_mutex_lock(&philo->table->forks[philo->rfork]))
		return ;
	print_status(philo->table, philo->pid, "has taken a fork\n");
	if (pthread_mutex_lock(&philo->eating))
		return ;
	print_status(philo->table, philo->pid, "is eating\n");
	philo->table->nta++;
	philo->lta = time_in_ms();
	philo->iseating = 1;
	if (philo->table->tte > 0)
		usleep(philo->table->tte * 1000 - 20000);
	while (time_in_ms() - philo->lta < philo->table->tte)
		usleep(50);
	philo->iseating = 0;
	if (pthread_mutex_unlock(&philo->eating))
		return ;
	if (pthread_mutex_unlock(&philo->table->forks[philo->lfork]))
		return ;
	if (pthread_mutex_unlock(&philo->table->forks[philo->rfork]))
		return ;
}

static void	sleep_philo(t_philo *philo)
{
	philo->lts = time_in_ms();
	print_status(philo->table, philo->pid, "is sleeping\n");
	if (philo->table->tts > 0)
		usleep(philo->table->tts * 1000 - 20000);
	while (time_in_ms() - philo->lts < philo->table->tts)
		usleep(50);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->table->death)
	{
		eat_philo(philo);
		sleep_philo(philo);
		think_philo(philo);
		usleep(100);
	}
	return (NULL);
}

void	*watchers(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->table->death)
	{
		if (philo->table->nph == 1)
		{
			usleep(1000 * philo->table->ttd - 100);
			print_status(philo->table, philo->pid, "died\n");
			philo->table->death = 0;
		}
		if (!philo->iseating && time_in_ms() - philo->lta >= philo->table->ttd)
		{
			if (pthread_mutex_lock(&philo->eating))
				return (NULL);
			print_status(philo->table, philo->pid, "died\n");
			philo->table->death = 0;
			if (pthread_mutex_unlock(&philo->eating))
				return (NULL);
		}
		if (philo->table->nta == (philo->table->nte * philo->table->nph))
			philo->table->death = 0;
		usleep(100);
	}
	return (NULL);
}
