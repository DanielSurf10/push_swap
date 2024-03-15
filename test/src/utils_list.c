/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:56:26 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 22:48:37 by danbarbo         ###   ########.fr       */
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

/**
 * @brief Gets the node with the minimum sorted position that is greater than
 *        the sorted position of a given node.
 *
 * @param lst The list to search in.
 * @param node The node to compare the sorted position with.
 * @return The node with the minimum sorted position that is greater than the
 *         sorted position of the given node.
 */
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

/**
 * @brief Assigns the cost to each node in the list.
 *
 * @param lst_a The list that will receive the values.
 * @param lst_b The list that will provide the values.
 */
void	lst_assign_cost(t_list *lst_a, t_list *lst_b)
{
	int		lst_a_size;
	int		lst_b_size;
	t_list	*aux;
	t_list	*min_greather_than;

	lst_a_size = ft_lstsize(lst_a);
	lst_b_size = ft_lstsize(lst_b);
	aux = lst_b;
	min_greather_than = lst_b;
	while (aux)
	{
		min_greather_than = get_min_sorted_position_greater_than(lst_a, aux);
		if (min_greather_than->current_index > lst_a_size / 2)
			aux->cost_a = min_greather_than->current_index - lst_a_size;
		else
			aux->cost_a = min_greather_than->current_index;
		if (aux->current_index > lst_b_size / 2)
			aux->cost_b = aux->current_index - lst_b_size;
		else
			aux->cost_b = aux->current_index;
		aux = aux->next;
	}
}

/**
 * @brief Finds and performs the cheapest move to sort the list.
 *
 * @param lst_a The list that will receive the values.
 * @param lst_b The list that will provide the values.
 */
void	find_and_perform_cheapest_move(t_list **lst_a, t_list **lst_b)
{
	int		cheapest_move;
	t_list	*aux;
	t_list	*cheapest_node;

	aux = *lst_b;
	cheapest_node = *lst_b;
	cheapest_move = ft_abs(aux->cost_a) + ft_abs(aux->cost_b);
	while (aux)
	{
		if (ft_abs(aux->cost_a) + ft_abs(aux->cost_b) < cheapest_move)
		{
			cheapest_node = aux;
			cheapest_move = ft_abs(aux->cost_a) + ft_abs(aux->cost_b);
		}
		aux = aux->next;
	}
	while (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
	{
		rr(lst_a, lst_b);
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
	}
	while (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
	{
		rrr(lst_a, lst_b);
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
	}
	while (cheapest_node->cost_a != 0)
	{
		if (cheapest_node->cost_a > 0)
		{
			ra(lst_a);
			cheapest_node->cost_a--;
		}
		else
		{
			rra(lst_a);
			cheapest_node->cost_a++;
		}
	}
	while (cheapest_node->cost_b != 0)
	{
		if (cheapest_node->cost_b > 0)
		{
			rb(lst_b);
			cheapest_node->cost_b--;
		}
		else
		{
			rrb(lst_b);
			cheapest_node->cost_b++;
		}
	}
	pa(lst_b, lst_a);
}
