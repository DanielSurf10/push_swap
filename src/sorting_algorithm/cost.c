/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:01:42 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 22:45:34 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_assign_cost(t_list *lst_a, t_list *lst_b)
{
	int		lst_a_size;
	int		lst_b_size;
	t_list	*aux;
	t_list	*min_greather_than;

	lst_a_size = ft_lstsize(lst_a);
	lst_b_size = ft_lstsize(lst_b);
	aux = lst_b;
	min_greather_than = lst_b;
	while (aux)
	{
		min_greather_than = get_min_sorted_position_greater_than(lst_a, aux);
		if (min_greather_than->current_index > lst_a_size / 2)
			aux->cost_a = min_greather_than->current_index - lst_a_size;
		else
			aux->cost_a = min_greather_than->current_index;
		if (aux->current_index > lst_b_size / 2)
			aux->cost_b = aux->current_index - lst_b_size;
		else
			aux->cost_b = aux->current_index;
		aux = aux->next;
	}
}
