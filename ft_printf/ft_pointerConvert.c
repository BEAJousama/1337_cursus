/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerConvert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:40:28 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:40:30 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(void *pointer)
{
	int					t[1000];
	int					j;
	unsigned long int	nbr;
	char				*base;

	base = "0123456789abcdef";
	nbr = (unsigned long int)pointer;
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

void	ft_pointerconvert(va_list ap, int *count)
{
	void				*pointer;
	unsigned long int	nb;

	pointer = va_arg(ap, void *);
	ft_putstr("0x");
	ft_putnbr_base(pointer);
	nb = (unsigned long int)pointer;
	*count += ft_hex_len(nb) + 2;
}
