/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexConvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:37:59 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:38:05 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned int nbr, char c)
{
	int		t[1000];
	int		j;
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	j = 0;
	if (nbr == 0)
		ft_putchar(base[0]);
	while (nbr)
	{
		t[j] = nbr % 16;
		nbr = nbr / 16;
		j++;
	}
	while (--j >= 0)
		ft_putchar(base[t[j]]);
}

void	ft_hexconvert(va_list ap, int *count, char c)
{
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	ft_putnbr_base(nb, c);
	*count += ft_hex_len(nb);
}
