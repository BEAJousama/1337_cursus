/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:49:22 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/25 12:49:52 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_int_tab(int *tab, int size)
{
	int	j;
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (i < size)
	{
		j = i;
		while (j > 0 && tab[j - 1] > tab[j])
		{
			tmp = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = tmp;
			j--;
		}
		i++;
	}
}

int	*sorted_table(t_stack **a)
{
	t_stack	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tab = malloc(stacksize(*a) * sizeof(int));
	tmp = *a;
	while (tmp)
	{
		tab[i] = tmp -> data;
		tmp = tmp -> next;
		i++;
	}
	sort_int_tab(tab, stacksize(*a));
	return (tab);
}

void	push_inferior(t_stack **a, t_stack **b, int key_nbr)
{
	t_stack	*tmp;
	int		pos;

	tmp = *a;
	while (tmp)
	{
		if (tmp -> data < key_nbr)
		{
			pos = get_index(a, tmp -> data);
			if (pos <= stacksize(*a) / 2)
			{
				while (pos-- > 1)
					ra(a, 'p');
			}
			else
			{
				while (pos++ <= stacksize(*a))
					rra(a, 'p');
			}
			pb(a, b, 'p');
			tmp = *a;
			continue ;
		}
		tmp = tmp -> next;
	}
}

void	approximity(t_stack **a, t_stack **b, int j)
{
	int	pos;

	while (j--)
	{
		pos = get_min_index(a);
		if (pos <= stacksize(*a) / 2)
		{
			while (pos-- > 1)
				ra(a, 'p');
		}
		else
		{
			while (pos++ <= stacksize(*a))
				rra(a, 'p');
		}
		pb(a, b, 'p');
	}
}

void	push_superior(t_stack **a, t_stack **b, int to_push)
{
	int		pos;

	while (to_push--)
	{
		pos = get_index(b, get_max(b));
		if (pos <= stacksize(*b) / 2)
		{
			while (pos-- > 1)
				rb(b, 'p');
		}
		else
		{
			while (pos++ <= stacksize(*b))
				rrb(b, 'p');
		}
		if (*a)
			pa(a, b, 'p');
	}
}
