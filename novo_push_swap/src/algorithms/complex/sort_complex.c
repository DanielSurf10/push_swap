#include "push_swap.h"

void	sort_complex_algorithm(t_push_swap push_swap)
{
	int		index;
	int		key_nbr;
	int		key_nbr_factor;
	int		lst_size;
	int		moves_to_sort;
	t_list	*node;

	lst_size = ft_lstsize(push_swap.stack_a);

	key_nbr_factor = lst_size / 2;
	if (lst_size > 400)
		key_nbr_factor = ft_lstsize(push_swap.stack_a) / 4;
	key_nbr = key_nbr_factor;

	while (lst_size > 3)
	{
		node = lst_get_first_below(push_swap.stack_a, key_nbr);
		if (!node)
		{
			key_nbr += key_nbr_factor;
			continue ;
		}
		index = lst_get_index(push_swap.stack_a, node);
		if (index > lst_size / 2)
			index = index - lst_size;
		while (index != 0)
		{
			if (index > 0)
			{
				ra(&push_swap.stack_a);
				index--;
			}
			else
			{
				rra(&push_swap.stack_a);
				index++;
			}
		}
		pb(&push_swap.stack_a, &push_swap.stack_b);
		lst_size--;
	}

	if (push_swap.stack_a && is_list_sorted(push_swap.stack_a) == 0)
	{
		if (lst_size == 2)
			sa(&push_swap.stack_a);
		else if (lst_size == 3)
		{
			if (push_swap.stack_a == lst_get_max_value(push_swap.stack_a))		// Se o primeiro elemento for o maior dos 3
				ra(&push_swap.stack_a);
			else if (push_swap.stack_a->next == lst_get_max_value(push_swap.stack_a->next))		// Se o segundo elemento for o maior dos 3
				rra(&push_swap.stack_a);
			if (push_swap.stack_a->sorted_position > push_swap.stack_a->next->sorted_position)		// Se o segundo elementos for maior que o primeiro
				sa(&push_swap.stack_a);
		}
	}

	lst_size = ft_lstsize(push_swap.stack_b);

	while (lst_size > 0)
	{
		assign_current_indices(push_swap.stack_a);
		assign_current_indices(push_swap.stack_b);
		lst_assign_cost(push_swap.stack_a, push_swap.stack_b);
		// print_stack(push_swap.stack_a, push_swap.stack_b);
		find_and_perform_cheapest_move(&push_swap.stack_a, &push_swap.stack_b);
		lst_size--;
	}

	moves_to_sort = lst_get_index(push_swap.stack_a, lst_get_min_value(push_swap.stack_a));
	lst_size = ft_lstsize(push_swap.stack_a);

	if (moves_to_sort > lst_size / 2)
		moves_to_sort = moves_to_sort - lst_size;

	while (moves_to_sort != 0)
	{
		if (moves_to_sort > 0)
		{
			ra(&push_swap.stack_a);
			moves_to_sort--;
		}
		else
		{
			rra(&push_swap.stack_a);
			moves_to_sort++;
		}
	}
}
