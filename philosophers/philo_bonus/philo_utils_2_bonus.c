/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:30:38 by obeaj             #+#    #+#             */
/*   Updated: 2022/02/18 12:30:40 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	freetable(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nph)
	{
		if (table->philos[i])
		{
			if (table->philos[i]->eating)
				sem_close(table->philos[i]->eating);
			if (table->philos[i]->master)
				pthread_detach(table->philos[i]->master);
			if (table->philos[i])
				free(table->philos[i]);
		}
		i++;
	}
	if (table->philos)
		free(table->philos);
	if (table->forks)
		sem_close(table->forks);
	if (table->write)
		sem_close(table->write);
	free(table);
}
