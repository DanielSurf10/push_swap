/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:16:04 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 11:54:38 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_elements(t_push_swap *push_swap)
{
	if (push_swap->stack_a && is_list_sorted(push_swap->stack_a) == 0)
	{
		if (push_swap->lst_size == 2)
			sa(&push_swap->stack_a);
		else if (push_swap->lst_size == 3)
		{
			if (push_swap->stack_a == lst_get_max_value(push_swap->stack_a))
				ra(&push_swap->stack_a);
			else if (push_swap->stack_a->next
				== lst_get_max_value(push_swap->stack_a->next))
				rra(&push_swap->stack_a);
			if (push_swap->stack_a->sorted_position
				> push_swap->stack_a->next->sorted_position)
				sa(&push_swap->stack_a);
		}
	}
}

void	rotate_until_sorted(t_push_swap *push_swap)
{
	push_swap->moves_to_sort = lst_get_index(push_swap->stack_a,
			lst_get_min_value(push_swap->stack_a));
	push_swap->lst_size = ft_lstsize(push_swap->stack_a);
	if (push_swap->moves_to_sort > push_swap->lst_size / 2)
		push_swap->moves_to_sort = push_swap->moves_to_sort
			- push_swap->lst_size;
	while (push_swap->moves_to_sort != 0)
	{
		if (push_swap->moves_to_sort > 0)
		{
			ra(&push_swap->stack_a);
			push_swap->moves_to_sort--;
		}
		else
		{
			rra(&push_swap->stack_a);
			push_swap->moves_to_sort++;
		}
	}
}

void	sort(t_push_swap *push_swap)
{
	push_swap->lst_size = ft_lstsize(push_swap->stack_b);
	while (push_swap->lst_size > 0)
	{
		assign_current_indices(push_swap->stack_a);
		assign_current_indices(push_swap->stack_b);
		lst_assign_cost(push_swap->stack_a, push_swap->stack_b);
		find_and_perform_cheapest_move(&push_swap->stack_a,
			&push_swap->stack_b);
		push_swap->lst_size--;
	}
}

static void	rotate(t_list **stack_a, int index)
{
	if (index > 0)
		ra(stack_a);
	else
		rra(stack_a);
}

void	puts_nodes_to_b(t_push_swap *push_swap)
{
	while (push_swap->lst_size > 3)
	{
		push_swap->node = lst_get_first_below(push_swap->stack_a,
				push_swap->key_nbr);
		if (!push_swap->node)
			push_swap->key_nbr += push_swap->key_nbr_factor;
		else
		{
			push_swap->index = lst_get_index(push_swap->stack_a,
					push_swap->node);
			if (push_swap->index > push_swap->lst_size / 2)
				push_swap->index = push_swap->index - push_swap->lst_size;
			while (push_swap->index != 0)
			{
				rotate(&push_swap->stack_a, push_swap->index);
				if (push_swap->index > 0)
					push_swap->index--;
				else
					push_swap->index++;
			}
			pb(&push_swap->stack_a, &push_swap->stack_b);
			push_swap->lst_size--;
		}
	}
}
