/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:00:52 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/04 18:07:01 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_tot;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	len_tot = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (*s1 == '\0' && *s2 == '\0')
		s = ft_strdup("");
	else if (*s2 == '\0')
		s = ft_strdup(s1);
	else if (*s1 == '\0')
		s = ft_strdup(s2);
	else
	{
		s = (char *)malloc(len_tot * sizeof(char));
		if (!s)
			return (NULL);
		while (*s1)
			*s++ = *s1++;
		while (*s2)
			*s++ = *s2++;
		*s = '\0';
		s -= len_tot - 1;
	}
	return (s);
}
