/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:20:37 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/18 13:20:45 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const	char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_tot;
	char	*s;

	if (!s2 || !s1)
		return (NULL);
	len_tot = ft_strlen(s1) + ft_strlen(s2) + 2;
	s = (char *)malloc(len_tot * sizeof(char));
	if (!s)
		return (NULL);
	while (*s1)
		*s++ = *s1++;
	*s++ = ' ';
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (s - len_tot + 1);
}
