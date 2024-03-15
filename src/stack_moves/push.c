/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:00 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/14 22:38:03 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Moves the top element from lst_a to lst_b.
 *
 * @param lst_a The pointer to the first stack.
 * @param lst_b The pointer to the second stack.
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
	write(1, "pa\n", 3);
	lst_push(lst_b, lst_a);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	write(1, "pb\n", 3);
	lst_push(lst_a, lst_b);
}
