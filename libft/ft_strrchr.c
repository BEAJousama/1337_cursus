/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:30:40 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/04 11:06:52 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*a;

	a = s + ft_strlen(s);
	while (a != s - 1)
	{
		if (*a == (char)c)
			return ((char *)a);
		a--;
	}
	return (NULL);
}
