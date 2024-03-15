/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:23:02 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/19 10:33:22 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (is_sorted(*stack_a) != 1)
	{
		if (stack_size == 2)
			sa(stack_a, PRINT);
		else if (stack_size == 3)
			sort_3(stack_a);
		else
			sort(stack_a, stack_b, stack_size);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	argv = validate_args(argc, argv);
	stack_a = create_stack(argv);
	stack_b = NULL;
	stack_size = get_stack_len(stack_a);
	assign_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	exit_success();
}
