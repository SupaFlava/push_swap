/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:42:15 by rmhazres          #+#    #+#             */
/*   Updated: 2024/10/28 11:01:05 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*convert(int len);
static int	getlength(long nbr);

char	*ft_itoa(int n)
{
	int		length;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	length = getlength(nbr);
	result = convert(length);
	if (!result)
		return (NULL);
	i = length - 1;
	if (nbr == 0)
		result[i--] = '0';
	if (nbr < 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[length] = '\0';
	return (result);
}

static char	*convert(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	temp[0] = '0';
	return (temp);
}

static int	getlength(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
