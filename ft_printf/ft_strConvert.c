/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strConvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:40:43 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:40:47 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strconvert(va_list ap, int *count)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		write (1, "(null)", 6);
		*count += 6;
	}
	else
	{
		ft_putstr(s);
		*count += ft_strlen(s);
	}
}
