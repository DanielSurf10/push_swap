/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:52:38 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/16 16:52:41 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	get_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_len(stack_a);
	size_b = get_stack_len(stack_b);
	while (stack_b)
	{
		stack_b->cost_b = stack_b->position;
		stack_b->cost_a = stack_b->target_position;
		if (stack_b->cost_b > size_b / 2)
			stack_b->cost_b = (stack_b->cost_b - size_b);
		if (stack_b->cost_a > size_a / 2)
			stack_b->cost_a = (stack_b->cost_a - size_a);
		stack_b = stack_b->next;
	}
}

int	get_absolute_cost(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	if (a < 0 && b < 0)
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	return (ft_abs(a) + ft_abs(b));
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		abs_cost;

	tmp_b = *stack_b;
	cheapest = MAX_INT;
	while (tmp_b)
	{
		abs_cost = get_absolute_cost(tmp_b->cost_a, tmp_b->cost_b);
		if (abs_cost < cheapest)
		{
			cost_a = tmp_b->cost_a;
			cost_b = tmp_b->cost_b;
			cheapest = abs_cost;
		}
		tmp_b = tmp_b->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}
