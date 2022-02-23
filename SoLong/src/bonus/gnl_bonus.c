/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:00:53 by obeaj             #+#    #+#             */
/*   Updated: 2021/12/20 12:01:29 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_strjoin1_bonus(char *reste, char *buff)
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

static char	*readbuffer_bonus(char *reste, int fd)
{
	char	*buff;
	int		readen;

	buff = malloc(2);
	if (!buff)
		return (NULL);
	readen = 1;
	while (readen && !ft_strchr(reste, '\n'))
	{
		readen = read (fd, buff, 1);
		if (readen == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readen] = '\0';
		reste = ft_strjoin1_bonus(reste, buff);
	}
	free(buff);
	return (reste);
}

static char	*formatline_bonus(char *reste)
{
	char	*line;
	char	*ln;
	char	*res;
	int		len;

	if (!*reste)
		return (NULL);
	res = reste;
	len = 0;
	while (*res && *res != '\n')
	{
		res++;
		len++;
	}
	line = (char *)malloc(len * sizeof(char) + 2);
	if (!line)
		return (NULL);
	ln = line;
	res = reste;
	while (*res && *res != '\n')
		*line++ = *res++;
	if (*res == '\n')
		*line++ = '\n';
	*line = '\0';
	return (ln);
}

static char	*formatreste_bonus(char *reste)
{
	char	*res;
	char	*newreste;
	char	*pnewreste;

	res = reste;
	while (*res && *res != '\n')
		res++;
	if (!*res)
	{
		free(reste);
		return (NULL);
	}
	newreste = malloc(ft_strlen(res + 1) + 1);
	if (!newreste)
		return (NULL);
	pnewreste = newreste;
	res++;
	while (*res)
		*pnewreste++ = *res++;
	*pnewreste = '\0';
	free(reste);
	return (newreste);
}

char	*get_next_line_bonus(int fd)
{
	static char	*reste;
	char		*line;

	if (fd < 0)
		return (NULL);
	reste = readbuffer_bonus(reste, fd);
	if (!reste)
		return (NULL);
	line = formatline_bonus(reste);
	reste = formatreste_bonus(reste);
	return (line);
}
