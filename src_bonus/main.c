/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:39:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 13:09:43 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	init(t_push_swap *push_swap, int argc, char **argv)
{
	push_swap->stack_a = make_stack(argc, argv);
	push_swap->stack_b = NULL;
	if (!push_swap->stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	assign_sorted_positions(push_swap->stack_a);
}

int	main(int argc, char *argv[])
{
	t_push_swap	push_swap;

	if (argc < 2)
		return (0);
	init(&push_swap, argc, argv);
	if (execute_sorting_instructions(&push_swap) == 0)
	{
		if (is_list_sorted(push_swap.stack_a) && push_swap.stack_b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_lstclear(&push_swap.stack_a, free);
	ft_lstclear(&push_swap.stack_b, free);
	return (0);
}
