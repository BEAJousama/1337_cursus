/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:01:40 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/19 17:01:54 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	small_sort(t_stack **a)
{
	int		max;

	max = get_max(a);
	if (stacksize(*a) == 2 && (*a)-> data > (*a)->next -> data)
	{
		sa(a, 'p');
		return ;
	}
	if (max == (*a)-> data)
	{
		ra(a, 'p');
		if ((*a)-> data > (*a)-> next -> data)
			sa(a, 'p');
	}
	if (max == ((*a)-> next -> data))
	{
		rra(a, 'p');
		if ((*a)-> data > (*a)-> next -> data)
			sa(a, 'p');
	}
	if (max == (*a)-> next -> next -> data
		&& (*a)-> data > (*a)-> next -> data)
		sa(a, 'p');
}

static void	ten_sort(t_stack **a, t_stack **b)
{
	int	i;

	i = stacksize(*a) - 3;
	approximity(a, b, i);
	small_sort(a);
	while (stacksize(*b))
		pa(a, b, 'p');
}

static void	hundred_sort(t_stack **a, t_stack **b)
{
	int		*tab;
	int		j;
	int		len;

	len = stacksize(*a);
	tab = sorted_table(a);
	push_inferior(a, b, tab[len / 5]);
	push_inferior(a, b, tab[len * 2 / 5]);
	push_inferior(a, b, tab[len * 3 / 5]);
	push_inferior(a, b, tab[len * 4 / 5]);
	j = len - 4 * len / 5;
	approximity(a, b, j);
	j = len / 5;
	while (j--)
		pa(a, b, 'p');
	push_superior(a, b, len * 4 / 5);
	if (*b)
		pa(a, b, 'p');
	free(tab);
}

static void	hundreds_sort(t_stack **a, t_stack **b)
{
	int		*tab;
	int		j;
	int		len;

	len = stacksize(*a);
	tab = sorted_table(a);
	push_inferior(a, b, tab[len / 10]);
	push_inferior(a, b, tab[len * 2 / 10]);
	push_inferior(a, b, tab[len * 3 / 10]);
	push_inferior(a, b, tab[len * 4 / 10]);
	push_inferior(a, b, tab[len * 5 / 10]);
	push_inferior(a, b, tab[len * 6 / 10]);
	push_inferior(a, b, tab[len * 7 / 10]);
	push_inferior(a, b, tab[len * 8 / 10]);
	push_inferior(a, b, tab[len * 9 / 10]);
	j = len - 9 * len / 10;
	approximity(a, b, j);
	j = len / 10;
	while (j--)
		pa(a, b, 'p');
	push_superior(a, b, len * 9 / 10);
	if (*b)
		pa(a, b, 'p');
	free(tab);
}

void	sorting(t_stack **a, t_stack **b)
{
	if (check_sorted(a))
	{
		freestack(a);
		freestack(b);
		exit(1);
	}
	if (stacksize(*a) == 3 || stacksize(*a) == 2)
		small_sort(a);
	else if (stacksize(*a) > 3 && stacksize(*a) <= 10)
		ten_sort(a, b);
	else if (stacksize(*a) > 10 && stacksize(*a) <= 100)
		hundred_sort(a, b);
	else if (stacksize(*a) > 100)
		hundreds_sort(a, b);
}
