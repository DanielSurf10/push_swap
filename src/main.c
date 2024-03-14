/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 00:39:36 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 00:10:29 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	push para a pilha b até sobrar 3 elementos
//	ordenar com 3 elementos
//	while até a pilha b acabar
//		Colocar a posição atual de cada nó nas 2 pilhas - pos
//		Na pilha B em cada nó - target
//			Colocar o target como o menor index da pilha A do que o nó respectivo da pilha B
//			Esse index na pilha A tem uma pos
//			E é isso que vai para o target no nó na pilha B
//		Calcular o cost
//			cost_a
//				É o target, só que ele pode ir pra cima (positivo) ou para baixo (negativo), em relação ao meio da pilha
//			cost_b
//				É a pos, só que ele pode ir pra cima (positivo) ou para baixo (negativo), em relação ao meio da pilha
//		Calcular o movimento com o menor custo
//			Ver qual é a menor soma entre cos_a e cos_b
//			Esse vai ser o movimento
//	acabou o while
//	Rotate ou rev rotate até estar totalmente ordenado

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
	t_list	*max;
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

	lst_assign_indices(push_swap.stack_a);

	lst_size = ft_lstsize(push_swap.stack_a);
	max = lst_max_value(push_swap.stack_a);

	if (lst_size < 10)
		key_nbr_factor = 0;
	else if (lst_size <= 100)
		key_nbr_factor = ft_lstsize(push_swap.stack_a) / 4;
	else if (lst_size <= 500)
		key_nbr_factor = ft_lstsize(push_swap.stack_a) / 8;
	else
		key_nbr_factor = ft_lstsize(push_swap.stack_a) / 16;
	key_nbr = key_nbr_factor;

	while (push_swap.stack_a && !(lst_is_sorted(push_swap.stack_a) && ft_lstlast(push_swap.stack_a) == max))
	{
		node = lst_min_group(push_swap.stack_a, key_nbr);
		if (node)
			min = *((int *)node->content);
		else
		{
			key_nbr += key_nbr_factor;
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
		}
		pb(&push_swap.stack_a, &push_swap.stack_b);
		lst_size--;
	}

	if (push_swap.stack_a && lst_is_sorted(push_swap.stack_a) == 0)
	{
		if (lst_size == 2)
			sa(&push_swap.stack_a);
		else if (lst_size == 3)
		{
			if (push_swap.stack_a == lst_max_value(push_swap.stack_a))		// Se o primeiro elemento for o maior dos 3
				ra(&push_swap.stack_a);
			else if (push_swap.stack_a->next == lst_max_value(push_swap.stack_a->next))		// Se o segundo elemento for o maior dos 3
				rra(&push_swap.stack_a);
			if (push_swap.stack_a->sorted_position > push_swap.stack_a->next->sorted_position)		// Se o segundo elementos for maior que o primeiro
				sa(&push_swap.stack_a);
		}
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
		}
		pa(&push_swap.stack_b, &push_swap.stack_a);
	}

	ft_lstclear(&push_swap.stack_a, free);

	return (0);
}
