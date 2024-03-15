/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leduard2 <leduard2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:53:55 by leduard2          #+#    #+#             */
/*   Updated: 2024/02/19 12:36:52 by leduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	apply_move(t_stack **stack_a, t_stack **stack_b, char *movement)
{
	if (ft_strncmp(movement, "ra\n", 3) == 0)
		ra(stack_a, NO_PRINT);
	else if (ft_strncmp(movement, "rb\n", 3) == 0)
		ra(stack_b, NO_PRINT);
	else if (ft_strncmp(movement, "rr\n", 3) == 0)
		rr(stack_a, stack_b, NO_PRINT);
	else if (ft_strncmp(movement, "rra\n", 4) == 0)
		rra(stack_a, NO_PRINT);
	else if (ft_strncmp(movement, "rrb\n", 4) == 0)
		rrb(stack_b, NO_PRINT);
	else if (ft_strncmp(movement, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, NO_PRINT);
	else if (ft_strncmp(movement, "sa\n", 3) == 0)
		sa(stack_a, NO_PRINT);
	else if (ft_strncmp(movement, "sb\n", 3) == 0)
		sb(stack_b, NO_PRINT);
	else if (ft_strncmp(movement, "ss\n", 3) == 0)
		ss(stack_a, stack_b, NO_PRINT);
	else if (ft_strncmp(movement, "pa\n", 3) == 0)
		pa(stack_a, stack_b, NO_PRINT);
	else if (ft_strncmp(movement, "pb\n", 3) == 0)
		pb(stack_a, stack_b, NO_PRINT);
	else
		exit_error();
}

void	read_and_move(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(0);
		if (line)
		{
			ft_collect_mem(line);
			apply_move(stack_a, stack_b, line);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	argv = validate_args(argc, argv);
	stack_a = create_stack(argv);
	stack_b = NULL;
	read_and_move(&stack_a, &stack_b);
	if (is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_success();
}
