/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:24:11 by obeaj             #+#    #+#             */
/*   Updated: 2022/01/19 13:24:16 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**initialize_philos(t_table *table)
{
	t_philo	**philos;
	int		i;

	philos = (t_philo **)malloc(sizeof(t_philo *) * (table->nph + 1));
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < table->nph)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo) * 1);
		if (philos[i] == NULL)
			return (NULL);
		if (pthread_mutex_init(&philos[i]->eating, 0) != 0)
			return (NULL);
		philos[i]->lfork = i;
		philos[i]->rfork = (i + 1) % table->nph;
		philos[i]->pid = i + 1;
		philos[i]->table = table;
		i++;
	}
	philos[i] = 0;
	return (philos);
}

pthread_mutex_t	*initialize_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->nph);
	if (!forks)
		return (NULL);
	while (i < table->nph)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}

t_table	*fill_table(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nph = ft_atoi(av[1]);
	table->ttd = ft_atoi(av[2]);
	table->tte = ft_atoi(av[3]);
	table->tts = ft_atoi(av[4]);
	table->death = 1;
	table->nte = -1;
	if (ac == 6)
		table->nte = ft_atoi(av[5]);
	table->forks = initialize_forks(table);
	if (!table->forks)
		return (NULL);
	table->philos = initialize_philos(table);
	if (!table->philos)
		return (NULL);
	if (pthread_mutex_init(&table->write, 0) != 0)
		return (NULL);
	return (table);
}

int	start_threads(t_table *table)
{
	table->index = 0;
	table->tval = time_in_ms();
	while (table->index < table->nph)
	{
		table->philos[table->index]->lta = time_in_ms();
		if (pthread_create(&table->philos[table->index]->slave, NULL,
				&routine, (void *)table->philos[table->index]) != 0)
			return (-1);
		usleep(100);
		table->index++;
	}
	table->index = 0;
	while (table->index < table->nph)
	{
		if (pthread_create(&table->philos[table->index]->master, NULL,
				&watchers, (void *)table->philos[table->index]) != 0)
			return (-1);
		usleep(100);
		table->index++;
	}
	while (table->death != 0)
		usleep(1000);
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*table;
	int		i;

	if (check_args(ac, av))
		return (-6);
	table = fill_table(ac, av);
	if (!table)
		return (-1);
	if (!table->nph || !table->nte)
	{
		freetable(table);
		return (-4);
	}
	i = start_threads(table);
	if (i)
		return (-3);
	if (i == 0)
	{
		if (threads_exit(table))
			return (-5);
	}
	return (0);
}
