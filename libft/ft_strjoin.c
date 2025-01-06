/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:32:38 by rmhazres          #+#    #+#             */
/*   Updated: 2024/10/18 12:23:37 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	newstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstring)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstring[i] = s2[j];
		i++;
		j++;
	}
	newstring[i] = '\0';
	return (newstring);
}
