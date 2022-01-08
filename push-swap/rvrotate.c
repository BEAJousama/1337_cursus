/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rvrotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:28:34 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/16 13:30:05 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rvrotate(t_stack **s)
{
	t_stack	*head;
	t_stack	*tail;
	t_stack	*tmp;

	if (!s || !*s)
		return ;
	head = *s;
	while (head -> next != NULL)
	{
		head = head -> next;
	}
	tail = head;
	tmp = ft_lstnew(tail -> data);
	ft_lstadd_front(s, tmp);
	head = *s;
	while (head -> next != tail)
		head = head -> next;
	head -> next = NULL;
	free(tail);
}

void	rra(t_stack **s, char c)
{
	rvrotate(s);
	if (c == 'p')
		write(1, "rra\n", 4);
}

void	rrb(t_stack **s, char c)
{
	rvrotate(s);
	if (c == 'p')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, char c)
{
	rvrotate(a);
	rvrotate(b);
	if (c == 'p')
		write(1, "rrr\n", 4);
}
