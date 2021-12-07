/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintConvert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:39:25 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:39:27 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunbr(unsigned int n)
{
	if (n < 10)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}

static int	ft_uint_len(unsigned int nb)
{
	int	i;

	i = 1;
	nb /= 10;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	ft_uintconvert(va_list ap, int *count)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ft_putunbr(nb);
	*count += ft_uint_len(nb);
}
