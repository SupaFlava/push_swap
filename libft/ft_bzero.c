/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:39:18 by rmhazres          #+#    #+#             */
/*   Updated: 2024/10/22 14:31:21 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *p, size_t num)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)p;
	i = 0;
	while (i < num)
	{
		ptr[i] = 0;
		i++;
	}
}
