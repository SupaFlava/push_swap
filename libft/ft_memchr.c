/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:22:13 by rmhazres          #+#    #+#             */
/*   Updated: 2024/10/18 12:19:27 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	toscan;

	string = (unsigned char *) s;
	toscan = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (string[i] == toscan)
		{
			return ((void *)&string[i]);
		}
		i++;
	}
	return (0);
}
