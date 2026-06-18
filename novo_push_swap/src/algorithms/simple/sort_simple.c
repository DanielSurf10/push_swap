#include "push_swap.h"

void	rotate_until_sorted(t_push_swap *push_swap)
{
	int	moves_to_sort;
	int	stack_size;

	moves_to_sort = lst_get_index(push_swap->stack_a, lst_get_min_value(push_swap->stack_a));
	stack_size = ft_lstsize(push_swap->stack_a);

	if (moves_to_sort > stack_size / 2)
		moves_to_sort = moves_to_sort - stack_size;

	while (moves_to_sort != 0)
	{
		if (moves_to_sort > 0)
		{
			ra(&push_swap->stack_a);
			moves_to_sort--;
		}
		else
		{
			rra(&push_swap->stack_a);
			moves_to_sort++;
		}
	}
}

void	sort_simple_algorithm(t_push_swap *push_swap)
{
	int				i;
	int				swap_flag;
	const int		stack_size = ft_lstsize(push_swap->stack_a);
	const t_list	*min_value = lst_get_min_value(push_swap->stack_a);
	const t_list	*max_value = lst_get_max_value(push_swap->stack_a);

	if (stack_size < 2)
		return ;
	i = stack_size;
	swap_flag = 1;
	while (swap_flag == 1)
	{
		swap_flag = 0;
		while (i > 0)
		{
			if (*(int *)push_swap->stack_a->content > *(int *)push_swap->stack_a->next->content
				&& !(push_swap->stack_a == max_value && push_swap->stack_a->next == min_value))
			{
				sa(&push_swap->stack_a);
				swap_flag = 1;
			}
			rra(&push_swap->stack_a);
			i--;
		}
		i = stack_size;
	}

	rotate_until_sorted(push_swap);
}
