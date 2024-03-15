/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:46:23 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/23 10:25:59 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_node(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	get_stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	add_node(t_stack *head, t_stack *new)
{
	t_stack	*stack;

	stack = get_last_node(head);
	stack->next = new;
	new->prev = stack;
}

t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = (t_stack *)ft_dalloc(1, sizeof(t_stack));
	new->value = value;
	new->index = -1;
	new->position = -1;
	new->target_position = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*create_stack(char **argv)
{
	t_stack	*stack_head;
	int		i;
	int		args_quantity;
	long	num;

	args_quantity = 0;
	while (argv[args_quantity] != NULL)
		args_quantity++;
	i = 0;
	stack_head = NULL;
	while (i < args_quantity)
	{
		num = ft_atol(argv[i]);
		if (stack_head == NULL)
			stack_head = new_stack((int)num);
		else
			add_node(stack_head, new_stack((int)num));
		i++;
	}
	return (stack_head);
}
