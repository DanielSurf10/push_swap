/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:39:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 17:59:10 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// [ ] - Não inicicado
// [-] - Iniciado
// [X] - Finalizado

//	[X] Colocar o sorted_position em cada nó na pilha A
//	[X]	Fazer push para a pilha b até sobrar 3 elementos
//	[X]	Ordenar com 3 elementos
//	[X]	while até a pilha b acabar
//	[X]		Colocar a posição atual de cada nó nas 2 pilhas - current_index
//	[X]		Na pilha B colocar o target em cada nó - absolute_target_pos
//				Colocar o target como o menor index da pilha A do que é maior que o nó respectivo da pilha B
//				Esse index na pilha A tem uma pos
//				E é isso que vai para o target no nó na pilha B
//	[X]		Calcular o cost
//				cost_a
//					É o target, só que ele pode ir pra cima (positivo) ou para baixo (negativo), em relação ao meio da pilha
//				cost_b
//					É a pos, só que ele pode ir pra cima (positivo) ou para baixo (negativo), em relação ao meio da pilha
//	[X]		Calcular o movimento com o menor custo
//				Ver qual é a menor soma entre cos_a e cos_b
//				Esse vai ser o movimento
//	Acabou o while
//	[X]	Rotate ou rev rotate até estar totalmente ordenado

int	main(int argc, char *argv[])
{
	t_push_swap	push_swap;

	int		index;
	int		key_nbr;
	int		key_nbr_factor;
	int		lst_size;
	int		moves_to_sort;
	t_list	*node;

	if (argc < 2)
		return (0);
	push_swap.stack_a = make_stack(argc, argv);
	push_swap.stack_b = NULL;

	if (!push_swap.stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	assign_sorted_positions(push_swap.stack_a);

	if (is_list_sorted(push_swap.stack_a))
	{
		ft_lstclear(&push_swap.stack_a, free);
		return (0);
	}

	lst_size = ft_lstsize(push_swap.stack_a);
	// max = lst_get_max_value(push_swap.stack_a);

	// if (lst_size < 10)
	// 	key_nbr_factor = 0;
	// else if (lst_size <= 100)
	// 	key_nbr_factor = ft_lstsize(push_swap.stack_a) / 4;
	// else if (lst_size <= 500)
	// 	key_nbr_factor = ft_lstsize(push_swap.stack_a) / 8;
	// else
	// 	key_nbr_factor = ft_lstsize(push_swap.stack_a) / 16;
	// else
	key_nbr_factor = lst_size / 2;
	if (lst_size > 400)
		key_nbr_factor = ft_lstsize(push_swap.stack_a) / 4;
	key_nbr = key_nbr_factor;
	// print_stack(push_swap.stack_a, push_swap.stack_b);

	while (lst_size > 3)
	{
		node = lst_get_first_below(push_swap.stack_a, key_nbr);
		if (!node)
		{
			key_nbr += key_nbr_factor;
			continue ;
		}
		index = lst_get_index(push_swap.stack_a, node);
		if (index > lst_size / 2)
			index = index - lst_size;
		while (index != 0)
		{
			if (index > 0)
			{
				ra(&push_swap.stack_a);
				index--;
			}
			else
			{
				rra(&push_swap.stack_a);
				index++;
			}
		}
		pb(&push_swap.stack_a, &push_swap.stack_b);
		lst_size--;
	}

	if (push_swap.stack_a && is_list_sorted(push_swap.stack_a) == 0)
	{
		if (lst_size == 2)
			sa(&push_swap.stack_a);
		else if (lst_size == 3)
		{
			if (push_swap.stack_a == lst_get_max_value(push_swap.stack_a))		// Se o primeiro elemento for o maior dos 3
				ra(&push_swap.stack_a);
			else if (push_swap.stack_a->next == lst_get_max_value(push_swap.stack_a->next))		// Se o segundo elemento for o maior dos 3
				rra(&push_swap.stack_a);
			if (push_swap.stack_a->sorted_position > push_swap.stack_a->next->sorted_position)		// Se o segundo elementos for maior que o primeiro
				sa(&push_swap.stack_a);
		}
	}

	lst_size = ft_lstsize(push_swap.stack_b);

	while (lst_size > 0)
	{
		assign_current_indices(push_swap.stack_a);
		assign_current_indices(push_swap.stack_b);
		lst_assign_cost(push_swap.stack_a, push_swap.stack_b);
		// print_stack(push_swap.stack_a, push_swap.stack_b);
		find_and_perform_cheapest_move(&push_swap.stack_a, &push_swap.stack_b);
		lst_size--;
	}

	moves_to_sort = lst_get_index(push_swap.stack_a, lst_get_min_value(push_swap.stack_a));
	lst_size = ft_lstsize(push_swap.stack_a);

	if (moves_to_sort > lst_size / 2)
		moves_to_sort = moves_to_sort - lst_size;

	while (moves_to_sort != 0)
	{
		if (moves_to_sort > 0)
		{
			ra(&push_swap.stack_a);
			moves_to_sort--;
		}
		else
		{
			rra(&push_swap.stack_a);
			moves_to_sort++;
		}
	}

	ft_lstclear(&push_swap.stack_a, free);

	return (0);
}
