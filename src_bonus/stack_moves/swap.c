/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:55:28 by danbarbo          #+#    #+#             */
/*   Updated: 2024/03/15 10:23:44 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/**
 * @brief Swaps the first two nodes of a linked list.
 *
 * The first node becomes the second and the second node becomes the first.
 *
 * @param lst A pointer to a pointer to the linked list.
 */
static void	lst_swap(t_list **lst)
{
	int		lst_size;
	t_list	*first;
	t_list	*second;

	lst_size = ft_lstsize(*lst);
	if (lst_size >= 2)
	{
		first = *lst;
		second = (*lst)->next;
		first->next = second->next;
		second->next = first;
		*lst = second;
	}
}

void	sa(t_list **lst_a)
{
	lst_swap(lst_a);
}

void	sb(t_list **lst_b)
{
	lst_swap(lst_b);
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	lst_swap(lst_a);
	lst_swap(lst_b);
}
