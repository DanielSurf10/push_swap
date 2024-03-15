/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:01:28 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 22:52:32 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Gets the smallest value that is greater than the given position.
 *
 * @param lst The list to search in.
 * @return The node with the minimum sorted position in the list.
 */
static t_list	*get_smallest_value_greater_than(t_list *lst, t_list *node)
{
	int		num;
	t_list	*min;
	t_list	*aux;

	num = *((int *) node->content);
	min = lst_get_max_value(lst);
	if (!lst || !min || !min->content || num >= *((int *) min->content))
		return (NULL);
	aux = lst;
	while (aux)
	{
		if (aux->content && min->content)
			if (*((int *) aux->content) > num
				&& *((int *) aux->content) < *((int *) min->content))
				min = aux;
		aux = aux->next;
	}
	return (min);
}

void	assign_sorted_positions(t_list *lst)
{
	int		index;
	t_list	*min;

	index = 1;
	min = lst_get_min_value(lst);
	while (min)
	{
		min->sorted_position = index;
		min = get_smallest_value_greater_than(lst, min);
		index++;
	}
}

void	assign_current_indices(t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		aux->current_index = i;
		aux = aux->next;
		i++;
	}
}

t_list	*get_min_sorted_position_greater_than(t_list *lst, t_list *node)
{
	t_list	*min;
	t_list	*aux;

	min = lst_get_max_value(lst);
	if (node->sorted_position > min->sorted_position)
		return (lst_get_min_value(lst));
	aux = lst;
	while (aux)
	{
		if (aux->sorted_position > node->sorted_position
			&& aux->sorted_position < min->sorted_position)
			min = aux;
		aux = aux->next;
	}
	return (min);
}
