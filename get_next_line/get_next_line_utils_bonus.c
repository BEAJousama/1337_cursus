/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:43:06 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/20 17:43:15 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_bonus(const	char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr_bonus(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin_bonus(char *reste, char *buff)
{
	char	*str;
	char	*pstr;
	char	*preste;

	if (!reste)
	{
		reste = (char *)malloc(1 * sizeof(char));
		*reste = '\0';
	}
	if (!buff)
		return (NULL);
	str = malloc((ft_strlen_bonus(reste) + ft_strlen_bonus(buff) + 1));
	if (!str)
		return (NULL);
	pstr = str;
	preste = reste;
	if (preste)
		while (*preste)
			*str++ = *preste++;
	while (*buff)
		*str++ = *buff++;
	*str = '\0';
	free(reste);
	return (pstr);
}
