#include "push_swap.h"

static void	move_min_to_top(t_list **stack)
{
	int			moves_to_put_in_top;
	const int	lst_size = ft_lstsize(*stack);

	moves_to_put_in_top = lst_get_index(*stack, lst_get_min_value(*stack));

	if (moves_to_put_in_top > lst_size / 2)
		moves_to_put_in_top = moves_to_put_in_top - lst_size;

	while (moves_to_put_in_top != 0)
	{
		if (moves_to_put_in_top > 0)
		{
			ra(stack);
			moves_to_put_in_top--;
		}
		else
		{
			rra(stack);
			moves_to_put_in_top++;
		}
	}
}

void	sort_simple_algorithm(t_push_swap *push_swap)
{
	while (push_swap->stack_a)
	{
		move_min_to_top(&push_swap->stack_a);
		pb(&push_swap->stack_a, &push_swap->stack_b);
	}

	while (push_swap->stack_b)
		pa(&push_swap->stack_b, &push_swap->stack_a);
}
