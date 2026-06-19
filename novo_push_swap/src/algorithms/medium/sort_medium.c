#include "push_swap.h"

void	move_to_stack_b(t_push_swap *push_swap)
{
	int		index;
	int		key_nbr;
	int		key_nbr_factor;
	int		lst_size;
	t_list	*node;

	lst_size = ft_lstsize(push_swap->stack_a);

	if (lst_size < 10)
		key_nbr_factor = 0;
	else if (lst_size <= 100)
		key_nbr_factor = ft_lstsize(push_swap->stack_a) / 4;
	else if (lst_size <= 500)
		key_nbr_factor = ft_lstsize(push_swap->stack_a) / 8;
	else
		key_nbr_factor = ft_lstsize(push_swap->stack_a) / 16;
	key_nbr = key_nbr_factor;

	while (lst_size > 0)
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
				ra(&push_swap->stack_a, &push_swap->bench);
				index--;
			}
			else
			{
				rra(&push_swap->stack_a, &push_swap->bench);
				index++;
			}
		}
		pb(&push_swap->stack_a, &push_swap->stack_b, &push_swap->bench);
		lst_size--;
	}
}

static void	move_min_to_top(t_list **stack, t_bench *bench)
{
	int			moves_to_put_in_top;
	const int	lst_size = ft_lstsize(*stack);;

	moves_to_put_in_top = lst_get_index(*stack, lst_get_max_value(*stack));

	if (moves_to_put_in_top > lst_size / 2)
		moves_to_put_in_top = moves_to_put_in_top - lst_size;

	while (moves_to_put_in_top != 0)
	{
		if (moves_to_put_in_top > 0)
		{
			rb(stack, bench);
			moves_to_put_in_top--;
		}
		else
		{
			rrb(stack, bench);
			moves_to_put_in_top++;
		}
	}
}

void	move_to_stack_a(t_push_swap *push_swap)
{
	while (push_swap->stack_b)
	{
		move_min_to_top(&push_swap->stack_b, &push_swap->bench);
		pa(&push_swap->stack_b, &push_swap->stack_a, &push_swap->bench);
	}
}

void	sort_medium_algorithm(t_push_swap *push_swap)
{
	move_to_stack_b(push_swap);
	move_to_stack_a(push_swap);
}
