/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:59:06 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/16 14:36:56 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swaping(t_stack **s)
{
	int	t;

	if (!s || !*s || !((*s)-> next))
		return ;
	t = (*s)-> data;
	(*s)-> data = (*s)-> next -> data;
	(*s)-> next -> data = t;
}

void	sa(t_stack **s, char c)
{
	swaping(s);
	if (c == 'p')
		write(1, "sa\n", 3);
}

void	sb(t_stack **s, char c)
{
	swaping(s);
	if (c == 'p')
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, char c)
{
	swaping(a);
	swaping(b);
	if (c == 'p')
		write(1, "ss\n", 3);
}
