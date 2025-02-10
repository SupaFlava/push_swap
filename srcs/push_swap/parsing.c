/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:28:04 by rmhazres          #+#    #+#             */
/*   Updated: 2025/02/06 12:47:06 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static const char	*skip_ws_sign(const char *s, int *sign)
{
	*sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n'
		|| *s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign = -1;
		s++;
	}
	return (s);
}

void	overflow(unsigned long r, int d, unsigned long l, t_s_node **a)
{
	if (r > l / 10)
		error_exit(a);
	if (r == l / 10 && (unsigned long)d > l % 10)
		error_exit(a);
}

static unsigned long	convert_digits(const char *s,
		unsigned long limit, t_s_node **a)
{
	unsigned long	res;
	int				digit;

	res = 0;
	while (*s && ft_isdigit(*s))
	{
		digit = *s - '0';
		overflow(res, digit, limit, a);
		res = res * 10 + digit;
		s++;
	}
	return (res);
}

long	ft_atol(const char *s, t_s_node **a)
{
	int				sign;
	unsigned long	limit;

	s = skip_ws_sign(s, &sign);
	if (sign == -1)
		limit = (unsigned long)INT_MAX + 1;
	else
		limit = INT_MAX;
	return ((long)convert_digits(s, limit, a) * sign);
}
