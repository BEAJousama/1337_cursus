/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:58:06 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/17 10:42:15 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_stack **s)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!s || !*s)
		return ;
	head = *s;
	tmp = ft_lstnew(head -> data);
	ft_lstadd_back(s, tmp);
	*s = (*s)-> next;
	free(head);
}

void	ra(t_stack **s, char c)
{
	rotate(s);
	if (c == 'p')
		write(1, "ra\n", 3);
}

void	rb(t_stack **s, char c)
{
	rotate(s);
	if (c == 'p')
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, char c)
{
	rotate(a);
	rotate(b);
	if (c == 'p')
		write(1, "rr\n", 3);
}
