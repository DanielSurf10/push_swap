/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:07:56 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 16:36:54 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Gets the absolute value of a number.
 *
 * @param num The number to be converted.
 * @return The integer.
 */
int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

float	compute_disorder(t_list *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*node_i;
	t_list	*node_j;

	mistakes = 0;
	total_pairs = 0;
	node_i = stack;
	while (node_i)
	{
		node_j = node_i->next;
		while (node_j)
		{
			total_pairs++;
			if (*(int *)node_i->content > *(int *)node_j->content)
				mistakes++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / (float)total_pairs);
}
