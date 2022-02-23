/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:59:09 by obeaj             #+#    #+#             */
/*   Updated: 2022/02/16 11:59:11 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	think_philo(t_philo *philo)
{
	print_status(philo->table, philo->pid, "is thinking");
}

static void	eat_philo(t_philo *philo)
{
	if (sem_wait(philo->table->forks))
		return ;
	print_status(philo->table, philo->pid, "has taken a fork");
	if (sem_wait(philo->table->forks))
		return ;
	print_status(philo->table, philo->pid, "has taken a fork");
	if (sem_wait(philo->eating))
		return ;
	print_status(philo->table, philo->pid, "is eating");
	philo->lta = time_in_ms();
	philo->nta++;
	usleep(philo->table->tte * 1000 - 10000);
	while (time_in_ms() - philo->lta < philo->table->tte)
		continue ;
	if (sem_post(philo->eating))
		return ;
	if (sem_post(philo->table->forks))
		return ;
	if (sem_post(philo->table->forks))
		return ;
	usleep(100);
}

static void	sleep_philo(t_philo *philo)
{
	philo->lts = time_in_ms();
	print_status(philo->table, philo->pid, "is sleeping");
	usleep(philo->table->tts * 1000 - 10000);
	while (time_in_ms() - philo->lts < philo->table->tts)
		continue ;
	usleep(100);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->nte > 0)
	{
		while (philo->nta <= philo->table->nte + 1)
		{
			eat_philo(philo);
			sleep_philo(philo);
			think_philo(philo);
			usleep(100);
		}
	}
	else
	{
		while (1)
		{
			eat_philo(philo);
			sleep_philo(philo);
			think_philo(philo);
			usleep(100);
		}
	}
	exit(1);
	return (NULL);
}

void	*watchers(void *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)data;
	while (1)
	{
		if (sem_wait(philo->eating))
			return (NULL);
		if (time_in_ms() - philo->lta >= philo->table->ttd)
			print_status(philo->table, philo->pid, "died");
		if (sem_post(philo->eating))
			return (NULL);
		usleep(100);
	}
	exit(0);
	return (NULL);
}
