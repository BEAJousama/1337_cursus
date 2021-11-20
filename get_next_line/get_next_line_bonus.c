/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:42:23 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/20 17:42:36 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*readbuffer_bonus(char *reste, int fd)
{
	char	*buff;
	int		readen;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readen = 1;
	while (readen && !ft_strchr_bonus(reste, '\n'))
	{
		readen = read (fd, buff, BUFFER_SIZE);
		if (readen == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readen] = '\0';
		reste = ft_strjoin_bonus(reste, buff);
	}
	free(buff);
	return (reste);
}

char	*formatline_bonus(char *reste)
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

char	*formatreste_bonus(char *reste)
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
	newreste = malloc(ft_strlen_bonus(res + 1) + 1);
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

char	*get_next_line(int fd)
{
	static char	*reste[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reste[fd] = readbuffer_bonus(reste[fd], fd);
	if (!reste[fd])
		return (NULL);
	line = formatline_bonus(reste[fd]);
	reste[fd] = formatreste_bonus(reste[fd]);
	return (line);
}
