/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:59:32 by obeaj             #+#    #+#             */
/*   Updated: 2022/02/16 11:59:34 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void	print_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit (1);
}

static int	check_nbr(char *av)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (av[i])
		i++;
	while (av[--i] == ' ')
		;
	while (av[j] == ' ')
		j++;
	if (av[j] > '9' || av[j] < '0')
		print_error(INVALID_ARGS);
	while (i != j)
	{
		if (av[i] > '9' || av[i] < '0')
		{
			print_error(INVALID_ARGS);
		}
		i--;
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	s;
	long	result;

	result = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		s *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result *= s;
	return (result);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		print_error(USAGE);
	while (av[++i])
	{
		if (check_nbr(av[i]))
			return (-3);
		if (ft_atoi(av[i]) > MAX_INT || ft_atoi(av[i]) < MIN_INT)
			print_error(OVERFLOW);
	}
	return (0);
}
