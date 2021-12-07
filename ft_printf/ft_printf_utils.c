/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:24:25 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:40:15 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest != NULL)
	{
		while (*(src + i))
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = '\0';
		return (dest);
	}
	return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const	char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_hex_len(unsigned long int nb)
{
	int	i;

	i = 1;
	nb /= 16;
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}
