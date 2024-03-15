/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:27:00 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/16 16:53:02 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_stack **stack_a, int b_idx)
{
	int		target_pos;
	int		target_idx;
	t_stack	*tmp;

	target_pos = MAX_INT;
	target_idx = MAX_INT;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > b_idx && tmp->index < target_idx)
		{
			target_pos = tmp->position;
			target_idx = tmp->index;
		}
		tmp = tmp->next;
	}
	if (target_idx != MAX_INT)
		return (target_pos);
	return (get_minimum_index(*stack_a)->position);
}

void	get_position(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->position = i;
		i++;
		stack = stack->next;
	}
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	get_position(*stack_a);
	get_position(*stack_b);
	while (tmp)
	{
		tmp->target_position = get_target(stack_a, tmp->index);
		tmp = tmp->next;
	}
}
