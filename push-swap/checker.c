/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:05:10 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/19 13:05:32 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	check_sort(t_stack **a, t_stack **b)
{
	if (!b || !a)
		return ;
	if (check_sorted(a) && !*b)
	{
		write(1, "OK\n", 4);
	}
	else
	{
		write(1, "KO\n", 4);
	}
	freestack(a);
	freestack(b);
	exit(1);
}

static void	check_errors(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "ra\n") && ft_strcmp(line, "rb\n")
		&& ft_strcmp(line, "sa\n") && ft_strcmp(line, "sb\n")
		&& ft_strcmp(line, "ss\n") && ft_strcmp(line, "rr\n")
		&& ft_strcmp(line, "rra\n") && ft_strcmp(line, "rrb\n")
		&& ft_strcmp(line, "rrr\n") && ft_strcmp(line, "pa\n")
		&& ft_strcmp(line, "pb\n"))
	{
		write(2, "Error\n", 7);
		free(line);
		freestack(a);
		freestack(b);
		exit(1);
	}
}

static void	checker_sorting(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a, 'c');
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 'c');
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 'c');
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 'c');
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 'c');
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 'c');
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b, 'c');
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 'c');
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 'c');
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 'c');
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 'c');
}

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;
	char	*line;

	a = NULL;
	b = NULL;
	a = stack_init(a);
	b = stack_init(b);
	fillstack(a, b, ac, av);
	line = get_next_line(0);
	while (line != NULL)
	{
		check_errors(a, b, line);
		checker_sorting(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	check_sort(a, b);
	return (0);
}
