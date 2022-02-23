/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:37:42 by obeaj             #+#    #+#             */
/*   Updated: 2022/02/08 10:37:44 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	print_error(char *s)
{
	ft_putendl_fd(s, 2);
	return (1);
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
	if ((av[j] > '9' || av[j] < '0') && print_error(INVALID_ARGS))
		return (-3);
	while (i != j)
	{
		if (av[i] > '9' || av[i] < '0')
		{
			if (print_error(INVALID_ARGS))
				return (-3);
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
		if (print_error(USAGE))
			return (-1);
	while (av[++i])
	{
		if (check_nbr(av[i]))
			return (-3);
		if (ft_atoi(av[i]) > MAX_INT || ft_atoi(av[i]) < MIN_INT)
		{
			if (print_error(OVERFLOW))
				return (-2);
		}
	}
	return (0);
}
