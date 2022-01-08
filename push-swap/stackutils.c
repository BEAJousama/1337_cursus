/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:51:00 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/17 11:51:14 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst -> data = data;
	lst -> next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	new -> next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (!lst)
		return ;
	if (*lst)
	{
		first = *lst;
		while (first -> next)
			first = first -> next;
		first -> next = new;
	}
	else
		*lst = new;
}

void	freestack(t_stack **s)
{
	while (*s)
	{
		free(*s);
		*s = (*s)-> next;
	}
	free(s);
}

t_stack	**stack_init(t_stack **s)
{
	s = malloc(sizeof(t_stack **));
	if (!s)
		return (NULL);
	*s = NULL;
	return (s);
}
