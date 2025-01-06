/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmhazres <rmhazres@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:46:28 by rmhazres          #+#    #+#             */
/*   Updated: 2025/01/06 12:39:46 by rmhazres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_push_swap(char stack_a)
{
	handle_data(stack_a);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	ft_push_swap(argv[1]);
	return (0);
}