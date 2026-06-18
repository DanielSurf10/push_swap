/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:56:26 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 18:26:48 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Gets the first value that is smaller than the given position.
 *
 * @param lst The list to search in.
 * @return The node found or min value if max_pos is 0.
 */
t_list	*lst_get_first_below(t_list *lst, int max_pos)
{
	if (max_pos == 0)
		return (lst_get_min_value(lst));
	while (lst)
	{
		if (lst->sorted_position <= max_pos)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

/**
 * @brief Gets the smallest value that is greater than the given position.
 *
 * @param lst The list to search in.
 * @return The node with the minimum sorted position in the list.
 */
t_list	*get_smallest_value_greater_than(t_list *lst, t_list *node)
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

/**
 * @brief Assigns the sorted position to each node in the list.
 *
 * The function assigns to each node the position it would have
 * if the list were sorted.
 *
 * @param lst The list to assign sorted positions to.
 */
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

/**
 * @brief Checks if a list is sorted.
 *
 * @param lst The list to check.
 * @return 1 if the list is sorted, 0 otherwise.
 */
int	is_list_sorted(t_list *lst)
{
	int		i;
	t_list	*aux;

	aux = lst;
	if (aux)
		i = lst->sorted_position;
	while (aux)
	{
		if (aux->sorted_position != i)
			return (0);
		aux = aux->next;
		i++;
	}
	return (1);
}

/**
 * @brief Assigns the current index to each node in the list.
 *
 * @param lst The list to assign current indices to.
 */
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
