/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:29:09 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/21 11:19:04 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *reste, char *buff)
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
	str = malloc(sizeof(char) * ((ft_strlen(reste) + ft_strlen(buff)) + 1));
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

size_t	ft_strlen(const	char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
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
