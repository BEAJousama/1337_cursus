/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:39:10 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:39:13 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_specifier(char c)
{
	int	i;

	i = 0;
	while (_SPECIFIERS[i])
	{
		if (c == _SPECIFIERS[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_vprintf(t_printf *format, va_list ap, int index, int *count)
{
	while (format->str[index] == ' ')
		index++;
	if (is_specifier(format->str[index]))
	{
		format->specifier = format->str[index];
		ft_conversion (format, ap, count);
	}
	else
	{
		ft_putchar(format->str[index]);
	}
	return (index);
}
