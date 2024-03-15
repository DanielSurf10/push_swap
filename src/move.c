/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:55:03 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 00:06:06 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_cheapest_node(t_list **lst_b)
{
	int		cheapest_move;
	t_list	*aux;
	t_list	*cheapest_node;

	aux = *lst_b;
	cheapest_node = *lst_b;
	cheapest_move = ft_abs(aux->cost_a) + ft_abs(aux->cost_b);
	while (aux)
	{
		if (ft_abs(aux->cost_a) + ft_abs(aux->cost_b) < cheapest_move)
		{
			cheapest_node = aux;
			cheapest_move = ft_abs(aux->cost_a) + ft_abs(aux->cost_b);
		}
		aux = aux->next;
	}
	return (cheapest_node);
}

static void	rotate_both(t_list *cheapest_node, t_list **lst_a, t_list **lst_b)
{
	while (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
	{
		rr(lst_a, lst_b);
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
	}
	while (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
	{
		rrr(lst_a, lst_b);
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
	}
}

static void	rotate_a(t_list *cheapest_node, t_list **lst_a)
{
	while (cheapest_node->cost_a != 0)
	{
		if (cheapest_node->cost_a > 0)
		{
			ra(lst_a);
			cheapest_node->cost_a--;
		}
		else
		{
			rra(lst_a);
			cheapest_node->cost_a++;
		}
	}
}

static void	rotate_b(t_list *cheapest_node, t_list **lst_b)
{
	while (cheapest_node->cost_b != 0)
	{
		if (cheapest_node->cost_b > 0)
		{
			rb(lst_b);
			cheapest_node->cost_b--;
		}
		else
		{
			rrb(lst_b);
			cheapest_node->cost_b++;
		}
	}
}

void	find_and_perform_cheapest_move(t_list **lst_a, t_list **lst_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest_node(lst_b);
	rotate_both(cheapest_node, lst_a, lst_b);
	rotate_a(cheapest_node, lst_a);
	rotate_b(cheapest_node, lst_b);
	pa(lst_b, lst_a);
}
