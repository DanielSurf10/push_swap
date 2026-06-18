#include "push_swap.h"

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

	if (!lst_b || !*lst_b)
		return ;
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

void	sort_complex_algorithm(t_push_swap *push_swap)
{
	int		index;
	int		key_nbr;
	int		key_nbr_factor;
	int		lst_size;
	int		moves_to_sort;
	t_list	*node;

	lst_size = ft_lstsize(push_swap->stack_a);

	key_nbr_factor = lst_size / 2;
	if (lst_size > 400)
		key_nbr_factor = ft_lstsize(push_swap->stack_a) / 4;
	key_nbr = key_nbr_factor;

	while (lst_size > 3)
	{
		node = lst_get_first_below(push_swap->stack_a, key_nbr);
		if (!node)
		{
			key_nbr += key_nbr_factor;
			continue ;
		}
		index = lst_get_index(push_swap->stack_a, node);
		if (index > lst_size / 2)
			index = index - lst_size;
		while (index != 0)
		{
			if (index > 0)
			{
				ra(&push_swap->stack_a);
				index--;
			}
			else
			{
				rra(&push_swap->stack_a);
				index++;
			}
		}
		pb(&push_swap->stack_a, &push_swap->stack_b);
		lst_size--;
	}

	if (push_swap->stack_a && is_list_sorted(push_swap->stack_a) == 0)
	{
		if (lst_size == 2)
			sa(&push_swap->stack_a);
		else if (lst_size == 3)
		{
			if (push_swap->stack_a == lst_get_max_value(push_swap->stack_a))		// Se o primeiro elemento for o maior dos 3
				ra(&push_swap->stack_a);
			else if (push_swap->stack_a->next == lst_get_max_value(push_swap->stack_a->next))		// Se o segundo elemento for o maior dos 3
				rra(&push_swap->stack_a);
			if (push_swap->stack_a->sorted_position > push_swap->stack_a->next->sorted_position)		// Se o segundo elementos for maior que o primeiro
				sa(&push_swap->stack_a);
		}
	}

	lst_size = ft_lstsize(push_swap->stack_b);

	while (lst_size > 0)
	{
		assign_current_indices(push_swap->stack_a);
		assign_current_indices(push_swap->stack_b);
		lst_assign_cost(push_swap->stack_a, push_swap->stack_b);
		// print_stack(push_swap->stack_a, push_swap->stack_b);
		find_and_perform_cheapest_move(&push_swap->stack_a, &push_swap->stack_b);
		lst_size--;
	}

	moves_to_sort = lst_get_index(push_swap->stack_a, lst_get_min_value(push_swap->stack_a));
	lst_size = ft_lstsize(push_swap->stack_a);

	if (moves_to_sort > lst_size / 2)
		moves_to_sort = moves_to_sort - lst_size;

	while (moves_to_sort != 0)
	{
		if (moves_to_sort > 0)
		{
			ra(&push_swap->stack_a);
			moves_to_sort--;
		}
		else
		{
			rra(&push_swap->stack_a);
			moves_to_sort++;
		}
	}
}
