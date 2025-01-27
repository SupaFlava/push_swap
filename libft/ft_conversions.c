/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:29:26 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/27 13:26:06 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(const char format, va_list args)
{
	int	printed_char;

	printed_char = 0;
	if (format == 'c')
		printed_char = ft_putchar(va_arg(args, int));
	else if (format == 's')
		printed_char = ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		printed_char = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		printed_char = ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		printed_char = ft_puthex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		printed_char = ft_putptr((unsigned long)va_arg(args, void *));
	else if (format == '%')
		printed_char = ft_putchar('%');
	else
	{
		printed_char = ft_putchar(format);
	}
	return (printed_char);
}
