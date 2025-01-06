/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:34:06 by rmhazres          #+#    #+#             */
/*   Updated: 2024/10/28 10:54:01 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*cdest;
	char	*csrc;

	if (dest == NULL && src == NULL )
		return (dest);
	cdest = (char *)dest;
	csrc = (char *)src;
	if (cdest > csrc && cdest < csrc + n)
	{
		while (n--)
		{
			cdest[n] = csrc[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
