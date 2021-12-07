/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:38:40 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:38:18 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			count;
	t_printf	format;
	int			i;

	format.str = ft_strdup(fmt);
	i = 0;
	count = 0;
	va_start(ap, fmt);
	while (format.str[i])
	{
		if (format.str[i] != '%')
		{
			ft_putchar (format.str[i]);
			count += 1;
		}
		else
		{
			i = ft_vprintf (&format, ap, ++i, &count);
		}
		i++;
	}
	va_end(ap);
	free(format.str);
	return (count);
}
