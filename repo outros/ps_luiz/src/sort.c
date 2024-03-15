/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:00 by leduard2          #+#    #+#             */
/*   Updated: 2024/03/13 13:53:01 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int	highest;

	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack, PRINT);
	else if ((*stack)->next->index == highest)
		rra(stack, PRINT);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack, PRINT);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	rotate_until_sorted(t_stack **stack)
{
	int	lowest_pos;
	int	stack_size;

	get_position(*stack);
	stack_size = get_stack_len(*stack);
	lowest_pos = get_minimum_index(*stack)->position;
	if (lowest_pos >= stack_size / 2)
		while ((*stack)->index != 0)
			rra(stack, PRINT);
	else
		while ((*stack)->index != 0)
			ra(stack, PRINT);
}

void	push_all_save_three(t_stack **stack_a, t_stack **stack_b,
		int stack_size)
{
	int	i;
	int	middle_index;
	int	total_len;

	i = 0;
	middle_index = stack_size / 2;
	total_len = stack_size;
	while (stack_size > 3 && i < total_len)
	{
		if ((*stack_a)->index <= middle_index)
		{
			pb(stack_a, stack_b, PRINT);
			stack_size--;
		}
		else
			ra(stack_a, PRINT);
		i++;
	}
	while (stack_size > 3)
	{
		pb(stack_a, stack_b, PRINT);
		stack_size--;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b, int stack_a_size)
{
	push_all_save_three(stack_a, stack_b, stack_a_size);
	sort_3(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(*stack_a, *stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		rotate_until_sorted(stack_a);
}
