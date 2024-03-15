/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:00 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 10:23:44 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 * @brief Moves the top element from lst_a to lst_b.
 *
 * @param lst_a The pointer to the stack that will give a node.
 * @param lst_b The pointer to the stack that will receive a node.
 */
static void	lst_push(t_list **lst_a, t_list **lst_b)
{
	t_list	*node_to_push;

	if ((*lst_a) == NULL)
		return ;
	node_to_push = *lst_a;
	*lst_a = (*lst_a)->next;
	node_to_push->next = *lst_b;
	*lst_b = node_to_push;
}

void	pa(t_list **lst_b, t_list **lst_a)
{
	lst_push(lst_b, lst_a);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	lst_push(lst_a, lst_b);
}
