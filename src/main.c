/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:39:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/11 19:24:31 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap	push_swap;

	int		proximity;
	int		proximity_b;
	int		min;
	int		max_b;
	int		index;
	int		index_b;
	int		key_nbr;
	int		key_nbr_factor;
	int		lst_size;
	t_list	*node;
	t_list	*node_b;

	if (argc < 2)
		return (0);
	push_swap.stack_a = make_stack(argc, argv);
	push_swap.stack_b = NULL;

	if (!push_swap.stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	// lst_assign_indices(push_swap.stack_a);

	lst_size = ft_lstsize(push_swap.stack_a);

	if (lst_size < 10)
		key_nbr = 0;
	else if (lst_size < 100)
		key_nbr_factor = ft_lstsize(push_swap.stack_a) / 4;
	else if (lst_size < 500)
		key_nbr_factor = ft_lstsize(push_swap.stack_a) / 8;
	else
		key_nbr_factor = ft_lstsize(push_swap.stack_a) / 16;
	key_nbr = key_nbr_factor;
	// node = lst_min_group(push_swap.stack_a, key_nbr);
	// if (node)
	// 	min = *((int *)node->content);
	// index = lst_get_index(push_swap.stack_a, min);
	// proximity = ft_lstsize(push_swap.stack_a) / 2;

	for (int i = 0; i < ft_lstsize(push_swap.stack_a); i++)
		printf("%2d - %d\n", lst_index(push_swap.stack_a, i)->pos, *((int *)lst_index(push_swap.stack_a, i)->content));


	while (push_swap.stack_a)
	{
		node = lst_min_group(push_swap.stack_a, key_nbr);
		if (node)
			min = *((int *)node->content);
		else
		{
			key_nbr += key_nbr_factor;
			// ft_putendl_fd("------------------------", 1);
			continue ;
		}
		index = lst_get_index(push_swap.stack_a, min);
		proximity = ft_lstsize(push_swap.stack_a) / 2;
		while (index != 0)
		{
			if (proximity > index)
					ra(&push_swap.stack_a);
			else
					rra(&push_swap.stack_a);
			index = lst_get_index(push_swap.stack_a, min);
			// if (index == -1)
			// 	break ;
			// ft_putnbr_fd(index, 1);
		}
		pb(&push_swap.stack_a, &push_swap.stack_b);
	}

	while (push_swap.stack_b)
	{
		node = lst_max_value(push_swap.stack_b);
		if (node)
			min = *((int *)node->content);
		index = lst_get_index(push_swap.stack_b, min);
		proximity = ft_lstsize(push_swap.stack_b) / 2;
		while (index != 0)
		{
			if (proximity > index)
				rb(&push_swap.stack_b);
			else
				rrb(&push_swap.stack_b);
			index = lst_get_index(push_swap.stack_b, min);
			// ft_putnbr_fd(index, 1);
		}
		pa(&push_swap.stack_b, &push_swap.stack_a);
	}

	ft_lstclear(&push_swap.stack_a, free);

	return (0);
}
