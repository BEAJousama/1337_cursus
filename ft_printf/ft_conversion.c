/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:37:37 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:37:42 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(t_printf *format, va_list ap, int *count)
{
	if (format->specifier == 'c')
		ft_charconvert(ap, count);
	else if (format->specifier == 's')
		ft_strconvert(ap, count);
	else if (format->specifier == 'u')
		ft_uintconvert(ap, count);
	else if (format->specifier == '%')
		ft_percentconvert(count);
	else if (format->specifier == 'x')
		ft_hexconvert(ap, count, 'x');
	else if (format->specifier == 'X')
		ft_hexconvert(ap, count, 'X');
	else if (format->specifier == 'p')
		ft_pointerconvert(ap, count);
	else if ((format->specifier == 'd') || (format->specifier == 'i'))
		ft_intconvert(ap, count);
}
