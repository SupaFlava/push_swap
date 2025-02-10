/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:23:43 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/27 14:02:09 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft.h"

typedef struct s_vars
{
	int	i;
	int	printed_chars;
}				t_vars;

int		ft_printf(const char *format, ...);
int		handle_conversion(const char format, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long long n);
int		ft_putunbr(unsigned int n);
int		ft_putptr(unsigned long ptr_value);
int		ft_puthex(unsigned long n, char format);

#endif