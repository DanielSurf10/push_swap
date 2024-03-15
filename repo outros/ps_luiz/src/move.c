/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:52:53 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/16 16:52:56 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cost_rr_both(t_stack **stack_a, t_stack **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b, PRINT);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	cost_rrr_both(t_stack **stack_a, t_stack **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b, PRINT);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	cost_ra_rra(t_stack **stack_a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(stack_a, PRINT);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(stack_a, PRINT);
		(*cost_a)++;
	}
}

static void	cost_rb_rrb(t_stack **stack_b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(stack_b, PRINT);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(stack_b, PRINT);
		(*cost_b)++;
	}
}

void	move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		cost_rr_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		cost_rrr_both(stack_a, stack_b, &cost_a, &cost_b);
	cost_ra_rra(stack_a, &cost_a);
	cost_rb_rrb(stack_b, &cost_b);
	pa(stack_a, stack_b, PRINT);
}
