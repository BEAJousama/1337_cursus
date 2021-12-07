/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 08:46:13 by obeaj             #+#    #+#             */
/*   Updated: 2021/11/28 15:38:24 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define _SPECIFIERS "uscdipxX%"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_printf
{
	char	*str;
	char	specifier;
}	t_printf;

char	*ft_strdup(const char *src);
void	ft_putstr(char *s);
void	ft_putchar(char c);
size_t	ft_strlen(const	char *s);
int		ft_printf(const char *fmt, ...);
int		ft_vprintf(t_printf *format, va_list ap, int index, int *count);
void	ft_conversion(t_printf *format, va_list ap, int *count);
int		ft_hex_len(unsigned long int nb);
void	ft_charconvert(va_list ap, int *count);
void	ft_intconvert(va_list ap, int *count);
void	ft_uintconvert(va_list ap, int *count);
void	ft_hexconvert(va_list ap, int *count, char c);
void	ft_strconvert(va_list ap, int *count);
void	ft_pointerconvert(va_list ap, int *count);
void	ft_percentconvert(int *count);

#endif
