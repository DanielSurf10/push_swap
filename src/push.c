/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:00 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/08 11:03:45 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_push(t_list **lst_a, t_list **lst_b)
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
