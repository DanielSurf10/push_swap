/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:39:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 23:51:24 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (is_list_sorted(push_swap->stack_a))
	{
		ft_lstclear(&push_swap->stack_a, free);
		exit(0);
	}
	push_swap->lst_size = ft_lstsize(push_swap->stack_a);
	push_swap->key_nbr_factor = push_swap->lst_size / 2;
	if (push_swap->lst_size > 400)
		push_swap->key_nbr_factor = ft_lstsize(push_swap->stack_a) / 4;
	push_swap->key_nbr = push_swap->key_nbr_factor;
}

int	main(int argc, char *argv[])
{
	t_push_swap	push_swap;

	if (argc < 2)
		return (0);
	init(&push_swap, argc, argv);
	pust_nodes_to_b(&push_swap);
	sort_3_elements(&push_swap);
	sort(&push_swap);
	rotate_until_sorted(&push_swap);
	ft_lstclear(&push_swap.stack_a, free);
	return (0);
}
