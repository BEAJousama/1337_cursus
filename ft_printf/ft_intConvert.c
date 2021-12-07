/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intConvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:38:50 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:38:59 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i < 10)
	{
		ft_putchar(i + 48);
	}
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

static int	ft_int_len(int nb)
{
	long	n;
	int		i;

	n = nb;
	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	n /= 10;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	ft_intconvert(va_list ap, int *count)
{
	int	nb;

	nb = va_arg(ap, int);
	ft_putnbr(nb);
	*count += ft_int_len(nb);
}
