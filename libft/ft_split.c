/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:24:32 by rmhazres          #+#    #+#             */
/*   Updated: 2024/10/28 11:33:14 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_countsub(const char *s, char c)
{
	size_t	count;
	int		insub;

	insub = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && insub == 0)
		{
			insub = 1;
			count++;
		}
		else if (*s == c)
		{
			insub = 0;
		}
		s++;
	}
	return (count);
}

static int	allocate(char **array, int start, size_t length)
{
	int	i;

	i = 0;
	array[start] = (char *)malloc((length + 1) * sizeof(char));
	if (array[start] == NULL)
	{
		while (i < start)
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (0);
	}
	return (1);
}

static	int	makecopy(char **array, const char *s, char c)
{
	int	i;
	int	start;
	int	arrayindex;

	i = 0;
	start = 0;
	arrayindex = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == '\0'
				|| (s[i + 1] == c && s[i] != c)))
		{
			if (!allocate(array, arrayindex, i - start + 1))
				return (0);
			ft_strlcpy(array[arrayindex], s + start, i - start + 2);
			arrayindex++;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	subindex;
	char	**array;

	if (s == NULL)
		return (NULL);
	subindex = ft_countsub(s, c);
	array = malloc((subindex + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (!makecopy(array, s, c))
		return (NULL);
	array[subindex] = NULL;
	return (array);
}
