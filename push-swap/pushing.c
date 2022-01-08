/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:37:43 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/17 15:43:58 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	pushing(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!a || !b || !*b)
		return ;
	tmp = ft_lstnew((*b)-> data);
	if (!*a)
		*a = tmp;
	else
		ft_lstadd_front(a, tmp);
	tmp1 = *b;
	*b = (*b)-> next;
	free(tmp1);
}

void	pb(t_stack **a, t_stack **b, char c)
{
	pushing(b, a);
	if (c == 'p')
		write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, char c)
{
	pushing(a, b);
	if (c == 'p')
		write(1, "pa\n", 3);
}
