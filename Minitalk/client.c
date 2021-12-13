/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:43:10 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/08 17:43:14 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bits(pid_t pid, char c)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		if (c & (1 << count))
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_putstr_fd("Error when sending SIGUSR2 signal !\n", 2);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr_fd("Error when sending SIGUSR1 signal !\n", 2);
		}
		count++;
		usleep(1000);
	}
}

static void	send_eof(pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_putstr_fd("Error when sending SIGUSR1 signal !\n", 2);
		usleep(1000);
		i++;
	}
}

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("\tOK!\t", 1);
}

int	main(int argc, char *argv[])
{
	char	*tab;
	int		i;

	if (argc != 3)
	{
		ft_putstr_fd("Usage : ./client <PID>  <STRING> \n", 1);
		return (0);
	}
	tab = ft_strdup(argv[2]);
	if (!tab)
		return (0);
	i = 0;
	signal(SIGUSR1, handler);
	while (tab[i])
	{
		send_bits((pid_t)ft_atoi(argv[1]), tab[i]);
		i++;
	}
	send_eof((pid_t)ft_atoi(argv[1]));
	free(tab);
	return (0);
}
