/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:33:22 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/17 15:37:19 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_isdigit(int c)
{
	if (c > '9' || c < '0')
		return (0);
	return (1);
}

static int	check_doubles(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[j]) == ft_atoi(tab[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	error_handler(t_stack **a, t_stack **b, char *t, char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		if (ft_atoi(tab[i]) > MAX_INT || ft_atoi(tab[i]) < MIN_INT)
		{
			freeall(tab, t, a, b);
			write(2, "Error\n", 6);
			exit(1);
		}
		while (tab[i][++j])
		{
			if (tab[i][j] == '-' || tab[i][j] == '+')
				j++;
			if ((!ft_isdigit(tab[i][j])) || !check_doubles(tab))
			{
				freeall(tab, t, a, b);
				write(2, "Error\n", 6);
				exit(1);
			}
		}
	}
}

static char	*parseargs(char **av)
{
	char	*t;
	char	*tmp;
	int		i;

	t = (char *)malloc(1 * sizeof(char));
	*t = '\0';
	i = 1;
	while (av[i])
	{
		tmp = t;
		t = ft_strjoin(t, av[i]);
		free(tmp);
		i++;
	}
	return (t);
}

void	fillstack(t_stack **a, t_stack **b, int ac, char **av)
{
	char	**tab;
	int		i;
	t_stack	*s;
	char	*t;

	if (ac < 2)
	{
		freestack(a);
		freestack(b);
		exit(1);
	}
	t = parseargs(av);
	tab = ft_split(t, ' ');
	error_handler(a, b, t, tab);
	i = 1;
	*a = ft_lstnew(ft_atoi(tab[0]));
	while (tab[i])
	{	
		s = ft_lstnew(ft_atoi(tab[i]));
		ft_lstadd_back(a, s);
		i++;
	}
	free(t);
	freetab(tab);
}
