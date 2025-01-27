/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:52:45 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/27 13:26:06 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_putnbr(long long n)
{
	int	count;

	count = 0;
	if (n == LLONG_MIN)
	{
		count += ft_putstr("-9223372036854775807");
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putptr(unsigned long ptr_value)
{
	int	count;

	count = 0;
	if (ptr_value == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	else
	{
		ft_putstr("0x");
		count += ft_puthex(ptr_value, 'x') + 2;
	}
	return (count);
}

int	ft_puthex(unsigned long n, char format)
{
	int		count;
	char	*hex;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
