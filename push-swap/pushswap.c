/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:49:05 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/17 15:42:09 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	a = NULL;
	b = NULL;
	a = stack_init(a);
	b = stack_init(b);
	fillstack(a, b, ac, av);
	sorting(a, b);
	freestack(a);
	freestack(b);
	return (0);
}
