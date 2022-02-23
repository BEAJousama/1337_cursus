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

#include "philo_bonus.h"

t_philo	**initialize_philos(t_table *table)
{
	t_philo	**philos;
	int		i;

	philos = (t_philo **)malloc(sizeof(t_philo *) * (table->nph));
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < table->nph)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo) * 1);
		if (philos[i] == NULL)
			return (NULL);
		sem_unlink("eating");
		philos[i]->eating = sem_open("eating", O_CREAT | O_EXCL, S_IRUSR
				| S_IWUSR, 1);
		philos[i]->pid = i + 1;
		philos[i]->table = table;
		i++;
	}
	return (philos);
}

sem_t	*initialize_forks(t_table *table)
{
	sem_t	*forks;
	int		i;

	i = 0;
	forks = NULL;
	sem_unlink("forks");
	forks = sem_open("forks", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, table->nph);
	sem_unlink("write");
	table->write = sem_open("write", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 1);
	return (forks);
}

t_table	*fill_table(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (NULL);
	table->nph = ft_atoi(av[1]);
	table->ttd = ft_atoi(av[2]);
	table->tte = ft_atoi(av[3]);
	table->tts = ft_atoi(av[4]);
	table->nte = -1;
	if (ac == 6)
		table->nte = ft_atoi(av[5]);
	table->forks = initialize_forks(table);
	table->philos = initialize_philos(table);
	if (!table->philos)
		return (NULL);
	if (!table->forks)
		return (NULL);
	return (table);
}

void	start_threads(t_table *table)
{
	int	i;

	i = 0;
	table->tval = time_in_ms();
	while (i < table->nph)
	{
		table->philos[i]->lta = time_in_ms();
		table -> philos[i]->slave = fork();
		if (table -> philos[i]->slave == 0)
		{
			if (pthread_create(&table->philos[i]->master, NULL,
					&watchers, (void *)table->philos[i]) != 0)
				return ;
			routine((void *)table->philos[i]);
		}
		usleep(150);
		i++;
	}
	kill_philos(table);
}

int	main(int ac, char **av)
{
	t_table	*table;
	int		i;

	i = 0;
	check_args(ac, av);
	table = fill_table(ac, av);
	if (!table)
		return (-1);
	if (!table->nph || !table->nte)
	{
		freetable(table);
		return (-4);
	}
	start_threads(table);
	freetable(table);
	return (0);
}
