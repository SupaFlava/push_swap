/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:21:26 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/27 13:26:06 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_printf( const char *format, ...)
{
	va_list			args;
	struct s_vars	vars;

	vars.i = 0;
	vars.printed_chars = 0 ;
	va_start(args, format);
	while (format[vars.i])
	{
		if (format[vars.i] == '%')
		{
			vars.i++;
			if (!format[vars.i])
				return (va_end(args), -1);
			else
				vars.printed_chars += handle_conversion(format[vars.i], args);
		}
		else
			vars.printed_chars += ft_putchar(format[vars.i]);
		if (vars.printed_chars == -1)
			return (va_end(args), -1);
		vars.i++;
	}
	va_end(args);
	return (vars.printed_chars);
}
